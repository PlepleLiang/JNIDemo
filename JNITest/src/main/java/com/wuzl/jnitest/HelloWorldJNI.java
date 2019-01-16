package com.wuzl.jnitest;

public class HelloWorldJNI {

    // 加载Native动态库（so库），动态库的名称后面在mk文件中会使用到
    static {
        System.loadLibrary("helloworld_jni");
    }

    // 定义Native方法
    public native String getString();

    public native String setString(String text);
}
