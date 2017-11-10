/*
 * DecodePhoto.h
 *
 *  Created on: 2017-11-05
 *      Author: Sabirjan
 */

#ifndef DECODEPHOTO_H_
#define DECODEPHOTO_H_
#include <jni.h>
#include <string.h>
#include <dlfcn.h>
typedef int * HMODULE;
typedef int (*Unpack)(const char*, const char*, int);
int Loaddl();
int CallWlt2Bmp(char* wltPath, char* bmpPath);
int CallWlt2BmpBytes(char *wlt, char *bmp);
#endif
