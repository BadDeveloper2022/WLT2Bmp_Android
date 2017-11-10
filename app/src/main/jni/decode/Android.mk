LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
# define so output folder
#NDK_APP_DST_DIR := libs/$(TARGET_ARCH_ABI)/usb

LOCAL_MODULE    := Wlt2Bmp
LOCAL_SRC_FILES += \
./Wlt2BmpUtils.cpp \

LOCAL_LDLIBS += -llog

LOCAL_STATIC_LIBRARIES	:= \
usbidcard \

include $(BUILD_SHARED_LIBRARY)


