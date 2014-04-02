#include "Test.h"
namespace android {
class BnTestService: public BnInterface<ITestService> {
public:
	virtual status_t
	onTransact(uint32_t code, const Parcel& data, Parcel* reply,
			uint32_t flags = 0);
	virtual void test() {
		printf("Now get test\n");
	}

};
status_t BnTestService::onTransact(uint_t code, const Parcel& data,
		Parcel* reply, uint32_t flags) {
	switch (code) {
	case TEST: {
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
int main() {
	sp < ProcessState > proc(ProcessState::self());
	sp < IServiceManager > sm = defaultServiceManager();
	sm->addService(String16("service.testservice"), new BnTestService());
	ProcessState::self()->startThreadPool();
	IPCThreadState::self()->joinThreadPool();
	return 0;
}
