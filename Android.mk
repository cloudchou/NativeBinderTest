LOCAL_PATH := $(call my-dir)
 

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
    libbinder       
LOCAL_MODULE    := TestServer
LOCAL_SRC_FILES := \
    ITestService.cpp \
    TestServer.cpp
   
LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)
  

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
    libbinder
LOCAL_MODULE    := TestClient
LOCAL_SRC_FILES := \
    ITestService.cpp \
    TestClient.cpp
LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)
