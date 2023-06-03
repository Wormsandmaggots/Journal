cmake_minimum_required(VERSION 3.25)
project(OpenGL)

set(CMAKE_CXX_STANDARD 23)

# to add something, remember to properly include and link directories
include_directories(${PROJECT_SOURCE_DIR}/Dependencies/GLFW/include)
link_directories(${PROJECT_SOURCE_DIR}/Dependencies/GLFW/lib)

# add target
add_executable(OpenGL main.cpp)

# remember to set paths to easier access
set(glfw ${PROJECT_SOURCE_DIR}/Dependencies/GLFW/lib/glfw3.dll)

# List of DLL dependencies
set(DEPENDENCIES
        ${glfw}
        )

# remember to add to target
target_link_libraries(OpenGL ${DEPENDENCIES} opengl32)
# and last but no least, remember to add dlls where your exe is

# Function to copy DLL file if it doesn't exist in the output directory
function(copy_dll_if_needed TARGET DLL_PATH)
    if (NOT TARGET)
        message(FATAL_ERROR "copy_dll_if_needed: TARGET not specified")
    endif()
    if (NOT DLL_PATH)
        message(FATAL_ERROR "copy_dll_if_needed: DLL_PATH not specified")
    endif()

    get_filename_component(DLL_NAME ${DLL_PATH} NAME)
    set(DLL_DEST ${DLL_NAME})

    add_custom_command(TARGET ${TARGET} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${DLL_PATH}"
            "${DLL_DEST}"
            COMMENT "Copying ${DLL_NAME} to output directory")

    if (NOT EXISTS ${DLL_DEST})
        message(WARNING "${DLL_NAME} not found in output directory, copying...")
        execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DLL_PATH}" "${DLL_DEST}")
    else()
        message(WARNING "${DLL_NAME} has been found in output directory, no need for copying")
    endif()
endfunction()

# Function to copy all DLL dependencies if needed
function(copy_dll_dependencies TARGET DEPENDENCIES)
    if (NOT TARGET)
        message(FATAL_ERROR "copy_dll_dependencies: TARGET not specified")
    endif()
    if (NOT DEPENDENCIES)
        message(FATAL_ERROR "copy_dll_dependencies: DEPENDENCIES not specified")
    endif()

    foreach (DLL_PATH ${DEPENDENCIES})
        copy_dll_if_needed(${TARGET} ${DLL_PATH})
    endforeach()
endfunction()

# Copy all DLL dependencies if not already present in output directory
copy_dll_dependencies(OpenGL "${DEPENDENCIES}")
