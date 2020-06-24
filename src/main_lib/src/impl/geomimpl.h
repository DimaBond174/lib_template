/*
 * This is the source code of SpecNet project
 * It is licensed under MIT License.
 *
 * Copyright (c) Dmitriy Bondarenko
 * feel free to contact me: specnet.messenger@gmail.com
 */

#ifndef  GeomImpl_H
#define  GeomImpl_H

class GeomImpl
{
public:
  const char *get_tag()  {  return TAG;  }
  void  apply_settings(const char *json,  int  json_len);
  int  check_restangle(const char *json,  int  json_len);

private:
  const char * const TAG  { "GeomLib" };
};

#endif // GeomImpl_H
