#  This is the source code of SpecNet project
#  It is licensed under MIT License.
#  Copyright (c) Dmitriy Bondarenko
#  feel free to contact me: specnet.messenger@gmail.com

# Configuration of the assembly
#   according to the selected components:

# System configuration
set(OS_INCLUDE
  ${SPEC_SRC_COMMON}/file
     )

set(OS_SRC
  ${SPEC_SRC_COMMON}/file/fileadapter.cpp
   )

# OS configuration
if("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
  message(STATUS "Linux was chosen ")
  set(OS_INCLUDE
    ${OS_INCLUDE}
    ${SPEC_SRC_COMMON}/system/linux
       )

  set(OS_SRC
    ${OS_SRC}
    ${SPEC_SRC_COMMON}/system/linux/linuxsystem.cpp
     )

  set(OS_LIBS
             dl
            pthread
            stdc++fs
         )

elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
   message(STATUS "Windows was chosen ")

set(OS_INCLUDE
  ${OS_INCLUDE}
  ${SPEC_SRC_COMMON}/system/windows
     )

set(OS_SRC
  ${OS_SRC}
  ${SPEC_SRC_COMMON}/system/windows/windowssystem.cpp
   )

   set(OS_DEFINITIONS
    "WIN32_LEAN_AND_MEAN"
    FD_SETSIZE=1024
  )
endif()
message("OS_SRC : ${OS_SRC}")
