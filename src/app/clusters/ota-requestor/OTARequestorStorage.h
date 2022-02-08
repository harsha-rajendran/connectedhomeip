#pragma once

using namespace chip::app::Clusters::OtaSoftwareUpdateRequestor;
namespace chip {
class OTARequestorStorage: public PersistentStorageDelegate
{
    public:
        virtual ~OTARequestorStorage() = default;

};
} // namespace chip
