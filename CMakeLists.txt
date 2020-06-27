#  This is the source code of SpecNet project
#  It is licensed under MIT License.
#  Copyright (c) Dmitriy Bondarenko
#  feel free to contact me: specnet.messenger@gmail.com

cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(lib_template)

set(Proj_VERSION  "1.0")


# TODO Set build type:
set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type Debug|Release")
message("CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

# TODO Set in code unit test:
option(Provide_inline_unit_tests "Provide inline unit tests" ON)
message("Provide_inline_unit_tests: ${Provide_inline_unit_tests}")

# TODO Set OpenCV path:
set(OPENCV_BUILD_PATH "/home/dbond/workspace5/git/OpenCV/build64.clang.static.debug" CACHE PATH "OpenCV OS build folder")
message("OPENCV_BUILD_PATH: ${OPENCV_BUILD_PATH}")

# TODO Needto build Tests :
option(CREATE_TESTS "Create tests" ON)

# TODO Set lib name:
set(PROJ_GEOM_LIB_NAME "geomlib" CACHE PATH "Geom lib name")
message("PROJ_GEOM_LIB_NAME: ${PROJ_GEOM_LIB_NAME}")


# TODO Set bin folder:
set(PROJ_EXEC_BIN_FOLDER "../geomlib_bin" CACHE PATH "Binary output folder")
message("PROJ_EXEC_BIN_FOLDER: ${PROJ_EXEC_BIN_FOLDER}")

# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# you can set CMAKE_BINARY_DIR for temp files:
#set(PROJ_TEMP_BINARY_DIR "../geomlib_bin_temp" CACHE PATH "Binary output TEMP folder")
#message("PROJ_TEMP_BINARY_DIR: ${PROJ_TEMP_BINARY_DIR}")
#message("CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")


set(SPEC_PROPERTIES
    DEBUG_POSTFIX             "d"
)
# TODO Enshure target build is what you want:
if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    set(SPEC_BUILD DDEBUG)
else()
    set(SPEC_BUILD DRELEASE)
endif()

# Output folder for binaries
set(SPEC_BUILD_DIR_REL ${CMAKE_CURRENT_SOURCE_DIR}/${PROJ_EXEC_BIN_FOLDER})
get_filename_component(SPEC_BUILD_DIR "${SPEC_BUILD_DIR_REL}"
                       REALPATH BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
message("SPEC_BUILD_DIR : ${SPEC_BUILD_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${SPEC_BUILD_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SPEC_BUILD_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SPEC_BUILD_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG  ${SPEC_BUILD_DIR})
#set(CMAKE_BINARY_DIR  ${SPEC_BUILD_DIR})

#set(SPEC_BUILD_DIR_REL ${CMAKE_CURRENT_SOURCE_DIR}/${PROJ_TEMP_BINARY_DIR})
#get_filename_component(CMAKE_BINARY_DIR "${SPEC_BUILD_DIR_REL}"
#                      REALPATH BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
#message("CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")


include(cmake/functions.cmake)

set(SPEC_INCLUDE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/common
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    )

set(SPEC_SRC_COMMON
      ${CMAKE_CURRENT_SOURCE_DIR}/src/common
      )

set(SPEC_LIB_DIR
          ${CMAKE_CURRENT_SOURCE_DIR}/static
          )

  # Configuration of the assembly
  #   according to the selected components:
set(SPEC_DEFINITIONS
      ${CMAKE_SYSTEM_NAME}
      ${CMAKE_BUILD_TYPE}
      ${SPEC_BUILD}
      SPEC_VERSION="${Proj_VERSION}"
  )

if (Provide_inline_unit_tests)
  message("will compile with Provide_inline_unit_tests")
  set(SPEC_DEFINITIONS
    ${SPEC_DEFINITIONS}
    Provide_inline_unit_tests
    )
endif()

message("SPEC_DEFINITIONS: ${SPEC_DEFINITIONS}")

include(cmake/common.cmake)

message("Bulding main lib")
add_subdirectory(src/main_lib)


if (CREATE_TESTS)
  message(STATUS "Building Tests..")
  add_subdirectory(src/main_test)
endif()

