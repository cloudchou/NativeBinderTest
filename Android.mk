LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
    libbinder    
LOCAL_MODULE    := libbindertest
LOCAL_SRC_FILES := Test.cpp
LOCAL_MODULE_TAGS := optional
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
    libbinder \
    libbindertest     
LOCAL_MODULE    := TestServer
LOCAL_SRC_FILES := TestServer.cpp
LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)
  

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
    libbinder \
    libbindertest
LOCAL_MODULE    := TestClient
LOCAL_SRC_FILES := TestClient.cpp
LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)
