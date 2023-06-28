cmake_minimum_required(VERSION 3.25)
project(Dependencies)

set(CMAKE_CXX_STANDARD 23)


# try finding targets 
add_subdirectory(Libs/JournalLib)


file(GLOB VENDOR_FILES "Vendor/*/lib/*.dll")
file(GLOB LIB_FILES "Libs/*/lib/*.dll")


# Function to copy all DLL dependencies to a specified destination directory
function(copy_dll_dependencies DESTINATION_DIR DEPENDENCIES)

    if (NOT DESTINATION_DIR)

        message(FATAL_ERROR "copy_dll_dependencies: DESTINATION_DIR not specified")

    endif()

    if (NOT DEPENDENCIES)

        message(FATAL_ERROR "copy_dll_dependencies: DEPENDENCIES not specified")

    endif()

    foreach (DLL_PATH ${DEPENDENCIES})

        get_filename_component(DLL_NAME ${DLL_PATH} NAME)
        set(DLL_DESTINATION ${DESTINATION_DIR}/${DLL_NAME})

        if (NOT EXISTS ${DLL_DESTINATION})

            message(WARNING "${DLL_NAME} not found in destination directory, copying...")
            execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DLL_PATH}" "${DLL_DESTINATION}")

        else()

            message(WARNING "${DLL_NAME} has been found in destination directory, no need for copying")

        endif()

    endforeach()

endfunction()


# Copy all DLL dependencies if not already present in output directory
copy_dll_dependencies(${PROJECT_SOURCE_DIR}/../cmake-build-debug "${VENDOR_FILES}")