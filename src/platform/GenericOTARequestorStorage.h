
#include <app/clusters/ota-requestor/OTARequestorStorage.h>

namespace chip {
class GenericOTARequestorStorage: public OTARequestorStorage
{

    CHIP_ERROR SyncGetKeyValue(const char * key, void * buffer, uint16_t & size) override
    {
        return DeviceLayer::PersistedStorage::KeyValueStoreMgr().Get(key, buffer, size);
    }

    CHIP_ERROR SyncSetKeyValue(const char * key, const void * value, uint16_t size) override
    {
        return DeviceLayer::PersistedStorage::KeyValueStoreMgr().Put(key, value, size);
    }

    CHIP_ERROR SyncDeleteKeyValue(const char * key) override
    {
        return DeviceLayer::PersistedStorage::KeyValueStoreMgr().Delete(key);
    }

};
} // namespace chip
