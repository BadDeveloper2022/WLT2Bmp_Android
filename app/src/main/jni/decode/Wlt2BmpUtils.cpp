#include <jni.h>
#include <malloc.h>
#include "Wlt2BmpUtils.h"
#include "../common/Android_Log.h"
#include "../decodetools/DecodePhoto.h"
JavaVM *mVM;
JNIEnv *m_Env;
int unpack(char *src, char *dst, int bmpSave);
JNIEXPORT jint  JNICALL Java_com_sabirjan_reader_tools_WltDecodeUtil_Wlt2Bmp
        (JNIEnv *env, jobject object,jbyteArray wlt,jbyteArray bmpparam)
{
	env->GetJavaVM(&mVM);
	jbyte *wlt_temp=env->GetByteArrayElements(wlt,0);
	char *wltchar=(char*)wlt_temp;
	jbyte *bmp=env->GetByteArrayElements(bmpparam,0);
	char *bmpchar=(char*)bmp;
	int ret = CallWlt2BmpBytes(wltchar,bmpchar);
	LOGE("------------------2---");
    free(wltchar);
    //free(bmpchar);
   return ret;
}


