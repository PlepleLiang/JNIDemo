//
// Created by Administrator on 2019/1/15.
//
# include <jni.h>
# include <stdio.h>
# include <cstring>
# include "com_wuzl_jnitest_HelloWorldJNI.h"

# ifdef _cplusplus
extern "C"
{
# endif

    JNIEXPORT jstring JNICALL Java_com_wuzl_jnitest_HelloWorldJNI_getString(JNIEnv *env, jobject obj){
        return env -> NewStringUTF("Get Hello world JNI!");
    }

    JNIEXPORT jstring JNICALL Java_com_wuzl_jnitest_HelloWorldJNI_setString(JNIEnv *env, jobject obj, jstring str){
        char* jnistr = (char *) env->GetStringUTFChars(str, NULL);
        strcat(jnistr,": I am JNI");
        return env -> NewStringUTF(jnistr);
    }
# ifdef _cplusplus
}
# endif


