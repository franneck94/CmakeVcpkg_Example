cmake_minimum_required(VERSION 3.16)

project(CppProjectTemplate VERSION 1.0.0 LANGUAGES C CXX)

# Global CMake variables are set here
set(CMAKE_CXX_STANDARD              23)
set(CMAKE_CXX_STANDARD_REQUIRED     OFF)
set(CMAKE_CXX_EXTENSIONS            OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS   ON)

# Project/Library Names
set(LIBRARY_NAME    "lib")
set(EXECUTABLE_NAME "main")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)
include(ConfigSafeGuards)
include(Warnings)
include(Docs)
include(FetchContent)
include(LTO)

if (ENABLE_LTO)
    find_lto(CXX)
endif()

FetchContent_Declare(
    nadjieb_mjpeg_streamer
    GIT_REPOSITORY https://github.com/nadjieb/cpp-mjpeg-streamer
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(nadjieb_mjpeg_streamer)

find_package(fmt REQUIRED)
find_package(range-v3 REQUIRED)
find_package(cxxopts REQUIRED)
find_package(catch2 REQUIRED)
find_package(jsoncpp REQUIRED)
find_package(open62541 REQUIRED)
find_package(OpenCV REQUIRED)
find_path(CPP_HTTPLIB_INCLUDE_DIRS "httplib.h")

add_subdirectory(src)
add_subdirectory(app)
