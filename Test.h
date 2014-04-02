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

}
#endif

