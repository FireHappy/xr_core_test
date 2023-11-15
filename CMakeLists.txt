cmake_minimum_required(VERSION 3.0.0)
project(rokid_xr_core VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_library(rokid_xr_core SHARED plane_tracking.cpp plane_tracking.h)

set_target_properties(rokid_xr_core PROPERTIES OUTPUT_NAME "rokid_xr_core")
set_target_properties(rokid_xr_core PROPERTIES LIBRARY_OUTPUT_DIRECTORY "/Users/chenlin/projects/UnityProjects/ARCoreDemo/Assets/com.rokid.xr.core/Runtime/MacOS")
