cmake_minimum_required(VERSION 3.25)
project(JournalLib)

set(CMAKE_CXX_STANDARD 23)


set(dir ${PROJECT_SOURCE_DIR}/lib)


#put dll to cmake-build-debug in dir where exe is
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${dir})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})


file(GLOB_RECURSE src ${PROJECT_SOURCE_DIR}/src/*.cpp)


add_library(JournalLib SHARED ${src})


target_compile_definitions(JournalLib PRIVATE JR_WINDOWS_PLATFORM JR_DLL)