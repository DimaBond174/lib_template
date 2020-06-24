#  This is the source code of SpecNet project
#  It is licensed under MIT License.
#  Copyright (c) Dmitriy Bondarenko
#  feel free to contact me: specnet.messenger@gmail.com

# ************** Prepare **************
#set(
#  TEST_DEFINITION
#  DEF_NETWORK_DEBUG=1
#  )
#include(cmake/prepare.cmake)
set(LIB_NAME ${PROJ_GEOM_LIB_NAME})

# OpenCV :
#message("OPENCV_BUILD_PATH: ${OPENCV_BUILD_PATH}")
#find_package(OpenCV REQUIRED PATHS ${OPENCV_BUILD_PATH})

file(GLOB_RECURSE LIB_SRC
       ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
   )

set(LIB_SRC
  ${LIB_SRC}
  ${SPEC_SRC_COMMON}/config/json/configjson.cpp
  ${OS_SRC}
  )

set(LIB_INCLUDES
    ${SPEC_INCLUDE}
    ${CMAKE_CURRENT_SOURCE_DIR}/src    
    ${OS_INCLUDE}
#    ${OpenCV_INCLUDE_DIRS}
    )

set(LIB_DEFINITIONS
    ${SPEC_DEFINITIONS}    
#    ${TEST_DEFINITION}
    )

set(LIB_LINK_LIBS
  ${OS_LIBS}
#    ${OpenCV_LIBS}
    )

set(LIB_PROPERTIES
    ${SPEC_PROPERTIES}
    )

custom_add_lib( ${LIB_NAME}
    "${SPEC_BUILD_DIR}"
    "${LIB_SRC}"
    "${LIB_INCLUDES}"
    "${LIB_DEFINITIONS}"
    "${LIB_LINK_LIBS}"
    "${LIB_PROPERTIES}"
    )

