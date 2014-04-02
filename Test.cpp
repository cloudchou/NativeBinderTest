#include "Test.h"
namespace android
{
    IMPLEMENT_META_INTERFACE(TestService, "android.TestServer.ITestService");
    status_t
    BnTestService::onTransact(uint_t code, const Parcel& data, Parcel* reply, uint32_t flags) {
        switch (code)
            {
        case TEST:
            {
                printf("got the client msg\n");
                CHECK_INTERFACE(ITest, data, reply);
                test();
                reply->writeInt32(100);
                return NO_ERROR;
            }
            break;
        default:
            break;
            }
        return NO_ERROR;
    }
}
