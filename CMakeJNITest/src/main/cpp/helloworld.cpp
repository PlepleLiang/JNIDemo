# include <jni.h>
# include <stdio.h>
# include <cstring>

extern "C" {
    JNIEXPORT jstring JNICALL Java_com_wuzl_cmake_HelloWorldJNI_getString(JNIEnv *env, jobject obj){
        return env -> NewStringUTF("Get Hello world JNI");
    }

    JNIEXPORT jstring JNICALL Java_com_wuzl_cmake_HelloWorldJNI_setString(JNIEnv *env, jobject obj, jstring str){
        char* jnistr = (char *) env->GetStringUTFChars(str, NULL);
        strcat(jnistr,": I am JNI by CMake building");
        return env -> NewStringUTF(jnistr);
    }
}

