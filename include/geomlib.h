/*
 * This is the source code of SpecNet project
 * It is licensed under MIT License.
 *
 * Copyright (c) Dmitriy Bondarenko
 * feel free to contact me: specnet.messenger@gmail.com
 */

#ifndef GEOMLIB_H
#define GEOMLIB_H

#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_GeomLib
    #ifdef __GNUC__
      #define DLL_PUBLIC __attribute__ ((dllexport))
    #else
      #define DLL_PUBLIC __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #else
    #ifdef __GNUC__
      #define DLL_PUBLIC __attribute__ ((dllimport))
    #else
      #define DLL_PUBLIC __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #endif
  #define DLL_LOCAL
#else
  #if __GNUC__ >= 4
    #define DLL_PUBLIC __attribute__ ((visibility ("default")))
    #define DLL_LOCAL  __attribute__ ((visibility ("hidden")))
  #else
    #define DLL_PUBLIC
    #define DLL_LOCAL
  #endif
#endif


//extern "C" DLL_PUBLIC void set_logger(ILog *ilog);
extern "C" DLL_PUBLIC const char *get_tag();
extern "C" DLL_PUBLIC void apply_settings(const char *json,  int  json_len);

/*
  Check if the diagonals of the rectangle are the same
  JSON format:
  {
   "x1":123, "y1":123,
   "x2":123, "y2":123,
   "x3":123, "y3":123,
   "x4":123, "y4":123
  }
  Will check distance (x1,y1)-(x3,y3) vs (x2,y2)-(x4,y4)
 ---------------------
  Return 0 if distances are different, 1 if distances are same
*/
extern "C" DLL_PUBLIC int check_restangle(const char *json,  int  json_len);

#endif // GEOMLIB_H
