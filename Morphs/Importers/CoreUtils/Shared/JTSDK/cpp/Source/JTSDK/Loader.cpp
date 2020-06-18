/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include <iostream>

#include <JTSDK/Loader.h>

#include <JtTk/JtkEntityFactory.h>
#include <JtTk/JtkCADImporter.h>
#include <JtTk/JtkFault.h>

using namespace std;
using namespace JTSDK;

const char* printUnits(JtkUnits Units)
{
    switch (Units)
    {
    case JtkMICROMETERS:
    {
        return("micrometers");
        break;
    }
    case JtkMILLIMETERS:
    {
        return("mm");
        break;
    }
    case JtkCENTIMETERS:
    {
        return("cm");
        break;
    }
    case JtkDECIMETERS:
    {
        return("decimeters");
        break;
    }
    case JtkMETERS:
    {
        return("m");
        break;
    }
    case JtkKILOMETERS:
    {
        return("km");
        break;
    }
    case JtkINCHES:
    {
        return("in");
        break;
    }
    case JtkFEET:
    {
        return("ft");
        break;
    }
    case JtkYARDS:
    {
        return("yards");
        break;
    }
    case JtkMILES:
    {
        return("mi");
        break;
    }
    case JtkMILS:
    {
        return("mils");
        break;
    }
    case JtkUNKNOWN:
    {
        return("unknown");
        break;
    }
    default:
    {
        return("unknown (not assigned)");
        break;
    }
    }
}

int handleNodes(JtkHierarchy* CurrNode, int Level, JtkClientData* data)
{
    LoaderContext* contextPtr = (LoaderContext *) data;

    // common data
    int nodeId = -1;
    CurrNode->getId(nodeId);
    JtkString name = CurrNode->name();
    
    switch (CurrNode->typeID())
    {
        case JtkEntity::JtkPART:
        {
            JtkUnits nodeUnits = JtkUNKNOWN;
            ((JtkUnitHierarchy*)CurrNode)->getUnits(nodeUnits);
            cout << CurrNode->typeIDName() << ": " << name
                << " ( ver = " << CurrNode->version()
                << ", id = " << nodeId
                << ", units = " << printUnits(nodeUnits);

            break;
        }
        case JtkEntity::JtkASSEMBLY:
        {
            JtkUnits nodeUnits = JtkUNKNOWN;
            ((JtkUnitHierarchy*)CurrNode)->getUnits(nodeUnits);
            cout << CurrNode->typeIDName() << ": " << name
                << " ( ver = " << CurrNode->version()
                << ", id = " << nodeId
                << ", #children = " << ((JtkAssembly*)CurrNode)->numChildren()
                << ", units = " << printUnits(nodeUnits);
            break;
        }
        case JtkEntity::JtkINSTANCE:
        {
            cout << CurrNode->typeIDName() << ": " << name
                << " ( id = " << nodeId
                << " )" << endl;
            break;
        }
    }
    /** 
     Jtk_OK returned from JtkTraverser::setupPreActionCallback recurses down into JtkAssembly nodes. Jtk_ERROR prevents recursion to any lower level. 
     */
    return Jtk_OK;
}

void handleFaults(JtkEntityList* pFaults, IErrorHandlerPtr pErrorHandler) {
    JtkEntityPtr<JtkEntityList> faults(pFaults);
    for (int i = 0; faults && i < faults->length(); i++)
    {
        JtkEntityPtr<JtkFault> fault = (JtkFault*)(*faults)[i];
    }
}

int checkReadLicenseKey()
{
    int result = Jtk_OK;

     // Try to create an JtkCADImporter to test for JT read licensing
    JtkEntityPtr<JtkCADImporter> jtreader;
    jtreader = JtkEntityFactory::createCADImporter();
    if (!jtreader)
    {
        cout << "No import license found." << endl;
        result = Jtk_ERROR;
    }

    return result;
}

bool JTSDK::Loader::loadDocument(unsigned char* Buffer, const int BuffLen, IConsumerPtr consumer) {
    // init JtTk
    JtkEntityFactory::init(JtkEntityFactory::JtkPARASOLID_ON, JtkEntityFactory::JtkENVIRONMENT_CURRENT, NULL);
    if (!checkReadLicenseKey())
    {
        cout << "Error. Invalid JtTk license key." << endl;
        return false;
    }

    JtkEntityPtr<JtkCADImporter> importer;
    importer = JtkEntityFactory::createCADImporter();
    if (importer)
    {
        importer->setBrepLoadOption(JtkCADImporter::JtkTESS_AND_BREP);
        importer->setXTBrepEditOption(JtkCADImporter::JtkXTBREP_FOR_EDIT_ON);
        importer->setShapeLoadOption(JtkCADImporter::JtkALL_LODS);

        JtkEntityList* faultsPtr = NULL;
        JtkEntityPtr<JtkHierarchy> root = importer->import(Buffer, BuffLen, faultsPtr);
        JtkEntityPtr<JtkEntityList> faults(faultsPtr);
        handleFaults(faults, m_errorHandler);

        if (root)
        {
            JtkEntityPtr<JtkTraverser> traverser = JtkEntityFactory::createTraverser();
            if (traverser)
            {
                traverser->setupPreActionCallback((JtkTraverseActionCB*)handleNodes);
                JtkEntityPtr<LoaderContext> ctx = JTSDK::Loader::createContext(consumer);
                traverser->traverseGraph(root, (JtkClientData*)ctx.ptr());
                ctx = NULL;
            }
            else
            {
                JtkError << "Unable to create JtkTraverser." << endl;
                return false;
            }
        }
        else
        {
            JtkError << "Unable to find root node.  Check file..." << endl;
            return false;
        }
    }
    else
    {
        JtkError << "Unable to create JtkCADImporter.  Check license..." << endl;
        return false;
    }

    // All JtkEntity based pointers need to be deallocated before a call to JtkEntityFactory::fini( ).
    // This is handled in this example through the use of the JtkEntityPtr class that ensures that when
    // it goes out of scope the encapsulated JtkEntity pointer is correct unref'd.

    // For the case of the 'importer' variable the scope of the JtkEntityPtr is such that it would only
    // unref the JtkCADImporter pointer after the call to fini. As such we explicitly assign the
    // JtkEntityPtr to NULL to force an unref.
    importer = NULL;

    return true;
}
