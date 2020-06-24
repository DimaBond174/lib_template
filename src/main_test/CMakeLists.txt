#  This is the source code of SpecNet project
#  It is licensed under MIT License.
#  Copyright (c) Dmitriy Bondarenko
#  feel free to contact me: specnet.messenger@gmail.com

# ************** Prepare **************
set(TEST_LINK_LIBS )
include(cmake/prepare.cmake)
message("TEST_LINK_LIBS: ${TEST_LINK_LIBS}")

set(TEST_INCLUDES
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Compile test exe without test:
set(EXE_NAME "test_exe")
set(EXE_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/test_exe/test_exe.cpp
    )

set(EXE_INCLUDE
    ${SPEC_INCLUDE}
    ${TEST_INCLUDES}
    )

set(EXE_DEFINITIONS
    ${SPEC_DEFINITIONS}
    )

set(EXE_LINK_LIBS	
  ${TEST_LINK_LIBS}
  #  "${PROJ_GEOM_LIB_NAME}"
    )

set(EXE_PROPERTIES
    "${SPEC_PROPERTIES}"
    )

custom_add_executable(${EXE_NAME}
    "${SPEC_BUILD_DIR}"
    "${EXE_SRC}"
    "${EXE_INCLUDE}"
    "${EXE_DEFINITIONS}"
    "${EXE_LINK_LIBS}"
    "${EXE_PROPERTIES}"
    )

# Compile test
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS         "-Wall -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused")
    set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

set(GOOGLETEST_ROOT external/googletest/googletest CACHE STRING "Google Test source root")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/${GOOGLETEST_ROOT}
    ${CMAKE_CURRENT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    ${TEST_INCLUDES}
    )

set(GOOGLETEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
    )

foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(googletest ${GOOGLETEST_SOURCES})

file(GLOB_RECURSE TESTS_SRC
       ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp
   )

add_executable(
     unit_tests
     ${TESTS_SRC}
     )

#add_executable(
#    unit_tests
#    test/main.cpp
#    test/test1.cpp
#    test/example_subtract.cpp
#    )

add_dependencies(unit_tests googletest)

target_link_libraries(
    unit_tests
    googletest
    ${TEST_LINK_LIBS}
    pthread
    )

include(CTest)
enable_testing()

add_test(unit ${PROJECT_BINARY_DIR}/unit_tests)
