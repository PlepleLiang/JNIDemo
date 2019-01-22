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
        char *jnistr = (char *) env->GetStringUTFChars(str, NULL);
        strcat(jnistr, ": I am JNI");
        return env -> NewStringUTF(jnistr);
    }

    jstring sayHello(JNIEnv *env, jobject obj, jstring str){
        char *name = (char *) env->GetStringUTFChars(str, NULL);

        strcat(name,":say hello ~~~~~");
        return env -> NewStringUTF(name);
    }


    jint JNI_OnLoad(JavaVM *vm, void *reserved) {

        JNIEnv *env = NULL;

        /*1. 通过JavaVM 虚拟机获取JNIEnv指针，最终需要通过JNIEnv与Java虚拟机打交道和Java方法进行通信*/
        if (vm->GetEnv((void **) &env, JNI_VERSION_1_4) != JNI_OK) {
            return JNI_EVERSION;
        }

        /*2. 构建JNINativeMethod数组（JAVA方法和JNI方法的映射关系表）*/
        static JNINativeMethod methods_table[] = {
                {"sayHi", "(Ljava/lang/String;)Ljava/lang/String;", (void *) sayHello},
        };

        /*3. 通过类路径查找jclass对象*/
        jclass clazz;
        clazz = (env)->FindClass("com/wuzl/jnitest/HelloWorldJNI");

        if (clazz == NULL) {
            return JNI_ERR;
        }

        /*4. 调用RegisterNative注册到JVM虚拟机，形成映射，参数三为注册native方法的数量*/
        if ((env)->RegisterNatives(clazz, methods_table, sizeof(methods_table)/sizeof(methods_table[0])) < 0 ) {
            return JNI_ERR;
        }

        (env)->DeleteLocalRef(clazz);

        return JNI_VERSION_1_4;
    }


# ifdef _cplusplus
}
# endif


