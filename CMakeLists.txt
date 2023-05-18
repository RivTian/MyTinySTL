cmake_minimum_required(VERSION 2.8)
project(MyTinySTL)

# version setting
set(MyTinySTL_VERSION_MAJOR 1)
set(MyTinySTL_VERSION_MINOR 0)
set(MyTinySTL_VERSION_PATCH 0)
set(MyTinySTL_VERSION "${MyTinySTL_VERSION_MAJOR}.${MyTinySTL_VERSION_MINOR}.${MyTinySTL_VERSION_PATCH}")
message(STATUS "The Version of this project is: ${MyTinySTL_VERSION}")

# build type
set(CMAKE_BUILD_TYPE release)

# Setting Compiler minimum Version
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GUN")
    # CXXFLAGS C++编译器的编译选项；-O2 开启优化； -Wall 告诉编译器 编译后显示所有警告；
    # -Wextra 启用一些未由-Wall启用的额外警告标志； -Wno-sign-compare 关闭当有符号转换为无符号时，有符号和无符号值比较产生的错误警告；
    # -Who-unused-but-set-variable ；  -Wno-array-bounds
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra -Wno-sign-compare -Who-unused-but-set-variable -Wno-array-bounds")
    # 未启用的配置
    # set(EXTRA_CXX_FLAGS -Weffc++ -Wswitch-default -Wfloat-equal -Wconversion -Wsign-conversion)
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "5.0.0")
        message(FATAL_ERROR "required GCC 5.0 or later")
    else ()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    endif ()
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra -Wno-sign-compare")
    # set(EXTRA_CXX_FLAGS -Weffc++ -Wswitch-default -Wfloat-equal -Wconversion -Wimplicit-fallthrough)
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "3.5.0")
        message(FATAL_ERROR "required Clang 3.5 or later")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    endif()
endif ()

message(STATUS "The cmake_cxx_flags is: ${CMAKE_CXX_FLAGS}")
add_subdirectory(${PROJECT_SOURCE_DIR}/Test)