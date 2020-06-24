/*
 * This is the source code of SpecNet project
 * It is licensed under MIT License.
 *
 * Copyright (c) Dmitriy Bondarenko
 * feel free to contact me: specnet.messenger@gmail.com
 */

#ifndef Test2Lib_H
#define Test2Lib_H

#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_Test2Lib
    #ifdef __GNUC__
      #define DLL_PUBLIC_T __attribute__ ((dllexport))
    #else
      #define DLL_PUBLIC_T __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #else
    #ifdef __GNUC__
      #define DLL_PUBLIC_T __attribute__ ((dllimport))
    #else
      #define DLL_PUBLIC_T __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #endif
  #define DLL_LOCAL_T
#else
  #if __GNUC__ >= 4
    #define DLL_PUBLIC_T __attribute__ ((visibility ("default")))
    #define DLL_LOCAL_T  __attribute__ ((visibility ("hidden")))
  #else
    #define DLL_PUBLIC_T
    #define DLL_LOCAL_T
  #endif
#endif

extern "C" DLL_PUBLIC_T int do_Test2();

#endif // Test2Lib_H
