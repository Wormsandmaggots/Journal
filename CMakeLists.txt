cmake_minimum_required(VERSION 3.25)
project(Journal)


set(CMAKE_CXX_STANDARD 23)

message(WARNING "$ENV{VULKAN_SDK}")

# to add something, remember to properly include and link directories
include_directories(
        Dependencies/Vendor/GLFW/include
        Dependencies/Vendor/GLEW/include
        Dependencies/Vendor/spdlog/include
        Dependencies/Vendor/GLM/include
        Dependencies/Libs/JournalLib/include
        include
        )


link_directories(
        Dependencies/Vendor/GLFW/lib
        Dependencies/Vendor/GLEW/lib
        Dependencies/Vendor/spdlog/build/lib
        )


#get all files matching format
file(GLOB src "src/*.cpp")
file(GLOB vulkan_src "src/Vulkan/*.cpp")
#file(GLOB include "include/*.h")


# add target
add_executable(Journal Sandbox/src/main.cpp ${src} ${vulkan_src})


find_package(Vulkan REQUIRED)


# remember to set paths to easier access
set(glfw ${PROJECT_SOURCE_DIR}/Dependencies/Vendor/GLFW/lib/glfw3.dll)
set(glew ${PROJECT_SOURCE_DIR}/Dependencies/Vendor/GLEW/lib/glew32.dll)


# adding subdirectories
add_subdirectory(Dependencies)


# List of DLL dependencies
set(DEPENDENCIES
        ${glfw}
        ${glew}
        ${Vulkan_LIBRARIES}
        JournalLib
        )


set(TO_RUN
        JournalLib
        )


# command for running libs to be up to date with dlls
foreach (target ${TO_RUN})
add_custom_command(TARGET Journal
        PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:${target}>
        $<TARGET_FILE_DIR:Journal>)

        message(WARNING "${target} has been successfully launched")
endforeach ()


#add dependency to build before program
#add_dependencies(Journal JournalLib)


# remember to add to target
target_compile_definitions(Journal PUBLIC GLEW_STATIC JR_WINDOWS_PLATFORM)
target_link_libraries(Journal ${DEPENDENCIES} opengl32 -static)
target_include_directories(Journal PRIVATE ${Vulkan_INCLUDE_DIRS})