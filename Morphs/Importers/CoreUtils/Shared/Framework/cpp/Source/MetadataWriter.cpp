/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.        *
*                                                       *
********************************************************/

#include "FrameworkPch.h"

#include <Framework/MetadataWriter.h>

#include <functional>
#include <vector>

#include <Framework/MetadataDefinition.h>
#include <Framework/FormatWriterUtils.h>

namespace Spectre
{
    namespace Framework
    {
        namespace V1
        {
            class MetadataWriter : public IMetadataWriter, public CommonFrameWriter
            {

            private:
                static const uint32_t sVERSION = 1;

            public:
                MetadataWriter();
                virtual ~MetadataWriter();

                virtual void BeginFrame(
                    std::shared_ptr<IBuffer> const& outputBuffer,
                    uint32_t numItems,
                    EByteOrder byteOrder);

                virtual Frame* EndFrame();

                virtual void BeginMetadata(uint32_t id, const char* name);
                virtual void EndMetadata();

                virtual uint32_t GetVersion() const
                {
                    return sVERSION;
                }

            protected:


            private:
                MetadataWriter(const MetadataWriter& rhs);

                // Info about current item
                uint32_t m_currID;
                std::wstring m_currName;
            };

            //---------------------------------------------------------------------
            MetadataWriter::MetadataWriter()
            {
                m_currID = 0;
            }

            //---------------------------------------------------------------------
            MetadataWriter::~MetadataWriter()
            {
            }

            //---------------------------------------------------------------------
            void MetadataWriter::BeginFrame(
                std::shared_ptr<IBuffer> const& outputBuffer,
                uint32_t numItems,
                EByteOrder byteOrder)
            {
                this->DoReset();
                this->DoBeginFrame(outputBuffer, numItems, byteOrder, kFrameMetadata);
            }

            //---------------------------------------------------------------------
            Frame* MetadataWriter::EndFrame()
            {
                return this->DoEndFrame();
            }

            //---------------------------------------------------------------------
            void MetadataWriter::BeginMetadata(uint32_t id, const char* name)
            {
                if (m_outputBuffer == nullptr)
                {
                    throw Utils::SpectreFailException("MetadataWriter::BeginMetadata: You must call BeginFrame first");
                }
                if (id == 0)
                {
                    throw Utils::SpectreInvalidArgException("MetadataWriter::BeginMetadata:Invalid itemID of 0 specified");
                }
                if (m_currID != 0)
                {
                    throw Utils::SpectreInvalidArgException("MetadataWriter::BeginMetadata: You must call EndMetadata first");
                }

                m_currID = id;

                if (name == nullptr)
                    name = ".";

                size_t len = strlen(name);

                m_currName.clear();
                m_currName.resize(len);
                for (size_t i = 0; i < len; ++i)
                {
                    m_currName[i] = (wchar_t)name[i];
                }
            }

            //---------------------------------------------------------------------
            void MetadataWriter::EndMetadata()
            {
                if (m_outputBuffer == nullptr)
                {
                    throw Utils::SpectreFailException("MetadataWriter::EndMetadata: NULL output buffer");
                }

                // Write header...

                uint32_t headerOffset = m_outputBuffer->ReserveSpace(sizeof(MetadataDefinition), 4);
                MetadataDefinition* pHeader = (MetadataDefinition*)m_outputBuffer->GetBuffer(headerOffset);
                pHeader->ID = m_byteSwapU32(m_currID);

                // Resize name if exceeds field size
                size_t maxNameLength = (m_currName.length() > UINT16_MAX/2) ? UINT16_MAX/2 : m_currName.length();
                pHeader->NameNumBytes = m_byteSwapU16((uint16_t)maxNameLength*2);
                m_currName.resize(maxNameLength);

                pHeader->Version = m_byteSwapU32(MetadataDefinition::kVersion0);

                // Write name
                if (m_currName.length() != 0)
                {
                    uint32_t nameOffset = m_outputBuffer->WriteDataRaw(m_currName.c_str(), (uint32_t)(m_currName.size() * 2), 2);

                    // m_outputBuffer could be resized during the write, reset the pHeader pointer
                    pHeader = (MetadataDefinition*)m_outputBuffer->GetBuffer(headerOffset);
                    pHeader->OffsetName = m_byteSwapU16((uint16_t)(nameOffset - headerOffset));
                }
                else
                {
                    pHeader->OffsetName = 0;
                }

                // Save offset

                m_savedItemOffsets.push_back(headerOffset);
                ++m_numItems;

                // Reset

                m_currID = 0;
                m_currName.clear();
            }


        } // Namespace V1

        SPECTRESDK_API IMetadataWriter* MetadataWriterCreate()
        {
            return new V1::MetadataWriter();
        }

        SPECTRESDK_API void MetadataWriterDestroy(IMetadataWriter*& pWriter)
        {
            // Note: the following two lines have no effect (the function would do nothing if pWriter is nullptr anyway).
            // Perhaps we should instead assert non-null input?
            if (pWriter == nullptr)
                return;

            delete pWriter;
            pWriter = nullptr;
        }

    }//Namespace Framework

}// Namespace Spectre
