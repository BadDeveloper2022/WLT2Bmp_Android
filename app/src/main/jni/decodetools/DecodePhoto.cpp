/*
 * DecodePhoto.cpp
 *
 *  Created on: 2017-11-05
 *      Author: Sabirjan
 */
#include "DecodePhoto.h"
#include "../common/Android_Log.h"
#include <jni.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pthread.h>

HMODULE hModuleWltRS = NULL;
Unpack unpackWltRS = 0;
int unpack(char *src,char *dst,int bmpSave);

int CallWlt2BmpBytes(char *wlt, char *bmp) {

    jint result;
    LOGE(">> ------CallWlt2BmpBytes");
    result = unpack(wlt, bmp, 0);
    LOGE("CallWlt2BmpBytes(),unpack complete!unpack result = %d", result);
    return result;

}