//
// Created by Leo on 2016/8/2.
//

//注意资源释放

#include "com_leo_jniexample_JniJavaClass.h"
#include <stdlib.h>
#include<android/log.h>


#define  LOG_TAG "jniexception"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

JNIEXPORT jint JNICALL Java_com_leo_jniexample_JniJavaClass_calculate
        (JNIEnv *env, jclass jclass1, jint a) {
    jint result = a / 10;
//    method 1
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        env->ThrowNew(env->FindClass("java/lang/Exception"), "jni Exception");
    }

//
    jthrowable jthrowable1 = NULL;
    jthrowable1 = env->ExceptionOccurred();
    if (jthrowable1) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        jclass newClss;
        newClss = env->FindClass("java/lang/Exception");
        if (newClss == NULL) {
            return -1;
        }
        env->ThrowNew(newClss, "custom Exception");
    }

    return result;
}

void Jni_Throw_Custom_Exception(JNIEnv *env, const char *name, const char *msg) {
    jclass cls = env->FindClass(name);
    if (cls != NULL) {
        env->ThrowNew(cls, msg);
    }
    env->DeleteLocalRef(cls);
}
