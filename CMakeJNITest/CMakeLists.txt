# CMake 最小工具版本要求，可通过SDK Manager 查看CMake的本地版本
# 该版本对Gradle有要求，比如3.10 版本需要Gragle 4.10+version才行
cmake_minimum_required(VERSION 3.6)

add_library( # Sets the name of the library.
             # 动态库的名称，与ndk-build中Android.mk 的模块名一样
             # 最终编译出来的动态库名称为：lib+library name
             helloworld

             # Sets the library as a shared library.
             # 编译库的类型，有静态库、动态库、和模块库
             SHARED

             # Provides a relative path to your source file(s).
             # C/C++ 源文件
             src/main/cpp/helloworld.cpp)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.
# 找到依赖库，比如下面将系统log-lib链接到helloworld动态库
find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.
# 配置库的链接
target_link_libraries( # Specifies the target library.
        helloworld

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib} )