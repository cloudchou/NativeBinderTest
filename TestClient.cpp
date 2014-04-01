#include "Test.h"
int
main() {
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder = sm->getService(String16("service.testservice"));
    sp<ITestService> cs = interface_cast<ITestService>(binder);
    cs->test();
    return 0;
}
