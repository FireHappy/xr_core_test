cmake_minimum_required(VERSION 3.0.0)
project(rokid_xr_core VERSION 0.1.0 LANGUAGES C CXX)

# 启用C++11标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_OSX_ARCHITECTURES "arm64") # 设置目标架构

include(CTest)
enable_testing()

file(GLOB HEADERS "include/*.h")
file(GLOB SOURCES "src/*.cpp")

add_library(rokid_xr_core SHARED ${SOURCES} ${HEADERS})

# 将头文件目录添加到包含路径中
target_include_directories(rokid_xr_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/include/utils
)

add_executable(main main.cpp) # 添加执行程序

target_link_libraries(main PRIVATE rokid_xr_core)

set_target_properties(rokid_xr_core PROPERTIES OUTPUT_NAME "rokid_xr_core")
set_target_properties(rokid_xr_core PROPERTIES LIBRARY_OUTPUT_DIRECTORY "/Users/chenlin/projects/UnityProjects/ARCoreDemo/Assets/Plugins/Android")

# 设置共享库的输出目录，并显式指定输出文件的扩展名为 .so
set_target_properties(rokid_xr_core PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib
    SUFFIX ".so"
)
