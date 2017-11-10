
#ifndef ANDROID_LOG_H_
#define ANDROID_LOG_H_

#include "android/log.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

static const char * TAG="Wlt2Bmp_native";
#define LOGI(fmt, args...) __android_log_print(ANDROID_LOG_INFO, TAG, fmt, ##args)
#define LOGW(fmt, args...) __android_log_print(ANDROID_LOG_WARN,  TAG, fmt, ##args)
#define LOGD(fmt, args...) __android_log_print(ANDROID_LOG_DEBUG, TAG, fmt, ##args)
#define LOGE(fmt, args...) __android_log_print(ANDROID_LOG_ERROR, TAG, fmt, ##args)

void Logfile(const char* fmt,...);

bool Read2WriteConfig(bool isRead,char *tag,char *result);


#endif

