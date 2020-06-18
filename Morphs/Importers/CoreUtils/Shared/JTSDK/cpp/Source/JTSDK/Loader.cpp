/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include <iostream>

#include <JTSDK/Loader.h>
#include <JTSDK/IConsumer.h>

#include <JtTk/JtkEntityFactory.h>
#include <JtTk/JtkCADImporter.h>


using namespace std;

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

bool JTSDK::Loader::loadDocument(const std::string& fileName, JTSDK::IConsumer * consumer) {
    // init JtTk
    JtkEntityFactory::init(JtkEntityFactory::JtkPARASOLID_ON, JtkEntityFactory::JtkENVIRONMENT_CURRENT, NULL);
    if (!checkReadLicenseKey())
    {
        cout << "Error. Invalid JtTk license key." << endl;
        return false;
    }
    return false;
}
