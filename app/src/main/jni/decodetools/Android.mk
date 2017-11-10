LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
# define so output folder
#NDK_APP_DST_DIR := libs/$(TARGET_ARCH_ABI)/usb

LOCAL_MODULE    := usbidcard
LOCAL_SRC_FILES += \
DecodePhoto.cpp \


LOCAL_LDLIBS += -L$(SYSROOT)/usr/lib -llog

LOCAL_STATIC_LIBRARIES	:= \
wlttobmp \
 
include $(BUILD_STATIC_LIBRARY)


