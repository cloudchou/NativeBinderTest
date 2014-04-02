#ifndef TEST_H_H
#define TEST_H_H
#include <stdio.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IBinder.h>
#include <binder/Binder.h>
#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
using namespace android;
namespace android
{
    class ITestService : public IInterface
    {
    public:
        DECLARE_META_INTERFACE(TestService); // declare macro
        virtual void test()=0;
    };

    enum
    {
        TEST = IBinder::FIRST_CALL_TRANSACTION,
    };

    class BpTestService : public BpInterface<ITestService>
    {
    public:
        BpTestService(const sp<IBinder>& impl) :
            BpInterface<ITestService>(impl) {
        }
        virtual void
        test() {
            printf("in the get Test\n");
            Parcel data, reply;
            data.writeInterfaceToken(ITestService::getInterfaceDescriptor());
            remote()->transact(TEST, data, &reply);
            printf("send Print %d\n", reply.readInt32());
        }
    };

    class BnTestService : public BnInterface<ITestService>
    {
    public:
        virtual status_t
        onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);
    };

    class TestService : public BnTestService
    {
        virtual void
        test() {
            printf("Now get test\n");
        }
    };
}
#endif

