# 当前模块路径，即Android.mk所在的文件目录
LOCAL_PATH       :=  $(call my-dir)

# 开始清除LOCAL_XXX变量
include              $(CLEAR_VARS)

# 动态库模块名称，Java代码中中加载动态库中使用System.loadLibrary("helloworld_jni");
LOCAL_MODULE     :=  helloworld_jni

# 编译的C/C++源文件，可多个，以空格隔开
LOCAL_SRC_FILES  :=  helloworld.cpp

# 开始动态编译生成动态库
include $(BUILD_SHARED_LIBRARY)
