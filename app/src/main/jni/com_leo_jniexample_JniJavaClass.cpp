//
// Created by Leo on 2016/8/2.
//
#include "com_leo_jniexample_JniJavaClass.h"

typedef enum android_log_priority {
    ANDROID_LOG_VERBOSE,
    ANDROID_LOG_DEBUG,
    ANDROID_LOG_INFO,
    ANDROID_LOG_WARN,
    ANDROID_LOG_ERROR,
    ANDROID_LOG_FATAL
} android_log_priority;


JNIEXPORT jint JNICALL Java_com_leo_jniexample_JniJavaClass_calculate
        (JNIEnv *env, jclass jclass1, jint a) {
    return a + 10;
}
