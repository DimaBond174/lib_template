#  This is the source code of SpecNet project
#  It is licensed under MIT License.
#  Copyright (c) Dmitriy Bondarenko
#  feel free to contact me: specnet.messenger@gmail.com

# Coping assets (TODO any change&rerun CMake to copy):
FILE(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets)
FILE(GLOB_RECURSE SpecAssets
    ${CMAKE_CURRENT_SOURCE_DIR}/test_assets/*.*
    ${CMAKE_CURRENT_SOURCE_DIR}/test_assets/*
)

FOREACH(file ${SpecAssets})
    FILE(RELATIVE_PATH
        ITEM_PATH_REL
        ${CMAKE_CURRENT_SOURCE_DIR}/test_assets
        ${file}
    )
    GET_FILENAME_COMPONENT(dirname ${ITEM_PATH_REL} DIRECTORY)
#    message("File: ${ITEM_PATH_REL}")
#    message("Relative path: ${dirname}")
    FILE(MAKE_DIRECTORY ${SPEC_BUILD_DIR}/test_assets/${dirname})
#    GET_FILENAME_COMPONENT(filename ${file} NAME)
    FILE(COPY ${file} DESTINATION ${SPEC_BUILD_DIR}/test_assets/${dirname})
ENDFOREACH()


# OpenCV for testclient:
#message("OPENCV_BUILD_PATH: ${OPENCV_BUILD_PATH}")
#find_package(OpenCV REQUIRED PATHS ${OPENCV_BUILD_PATH})

# Building test static libs
#-------------------------------------
set(LIB_test1 "testlib1")
set(TEST_LINK_LIBS
  ${TEST_LINK_LIBS}
  ${LIB_test1}
  )
set(LIB_test1_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/test1/test1_impl.cpp
  ${OS_SRC}
  )

set(LIB_test1_INCLUDES
    ${OS_INCLUDE}
    ${SPEC_INCLUDE}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    
#    ${OpenCV_INCLUDE_DIRS}
    )

set(LIB_test1_DEFINITIONS
    ${SPEC_DEFINITIONS}
    ${TEST_DEFINITION}
    )

set(LIB_test1_LINK_LIBS
    ${OS_LIBS}
    ${PROJ_GEOM_LIB_NAME}
#    ${OpenCV_LIBS}
    )

custom_add_static_lib( ${LIB_test1}
    "${SPEC_BUILD_DIR}"
    "${LIB_test1_SRC}"
    "${LIB_test1_INCLUDES}"
    "${LIB_test1_DEFINITIONS}"
    "${LIB_test1_LINK_LIBS}"
    )

#set(LIB_PROPERTIES
#    ${SPEC_PROPERTIES}
#    )

#custom_add_lib( ${LIB_test1}
#    "${SPEC_BUILD_DIR}"
#    "${LIB_test1_SRC}"
#    "${LIB_test1_INCLUDES}"
#    "${LIB_test1_DEFINITIONS}"
#    "${LIB_test1_LINK_LIBS}"
#    "${LIB_PROPERTIES}"
#    )
#-------------------------------------
set(LIB_test2 "testlib2")
set(TEST_LINK_LIBS
  ${TEST_LINK_LIBS}
  ${LIB_test2}
  )
set(LIB_test2_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/test2/test2_impl.cpp
  ${OS_SRC}
  )

set(LIB_test2_INCLUDES
    ${OS_INCLUDE}
    ${SPEC_INCLUDE}
    ${CMAKE_CURRENT_SOURCE_DIR}/src

#    ${OpenCV_INCLUDE_DIRS}
    )

set(LIB_test2_DEFINITIONS
    ${SPEC_DEFINITIONS}
    ${TEST_DEFINITION}
    )

set(LIB_test2_LINK_LIBS
    ${OS_LIBS}
    ${PROJ_GEOM_LIB_NAME}
#    ${OpenCV_LIBS}
    )

custom_add_static_lib( ${LIB_test2}
    "${SPEC_BUILD_DIR}"
    "${LIB_test2_SRC}"
    "${LIB_test2_INCLUDES}"
    "${LIB_test2_DEFINITIONS}"
    "${LIB_test2_LINK_LIBS}"
    )
#-------------------------------------



