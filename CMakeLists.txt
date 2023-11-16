cmake_minimum_required(VERSION 3.0.0)
project(rokid_xr_core VERSION 0.1.0 LANGUAGES C CXX)

# 启用C++11标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64") # 设置目标架构

include(CTest)
enable_testing()

add_library(rokid_xr_core SHARED plane_tracking.cpp plane_tracking.h)

# 将头文件目录添加到包含路径中
target_include_directories(rokid_xr_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(main main.cpp) # 添加执行程序

target_link_libraries(main PRIVATE rokid_xr_core)

set_target_properties(rokid_xr_core PROPERTIES OUTPUT_NAME "rokid_xr_core")
set_target_properties(rokid_xr_core PROPERTIES LIBRARY_OUTPUT_DIRECTORY "/Users/chenlin/projects/UnityProjects/ARCoreDemo/Assets/Plugins/MacOS")
