/*
 * This is the source code of SpecNet project
 * It is licensed under MIT License.
 *
 * Copyright (c) Dmitriy Bondarenko
 * feel free to contact me: specnet.messenger@gmail.com
 */

#define  BUILDING_GeomLib

#include "geomlib.h"
#include "impl/geomimpl.h"

/*********************** Encapsulation **********************/
static GeomImpl  impl; // internal linkage

/************************* Interface ************************/
const char *get_tag()
{
  return impl.get_tag();
}

void apply_settings(const char *json,  int  json_len)
{
  impl.apply_settings(json, json_len);
  return;
}

int check_restangle(const char *json,  int  json_len)
{
  return impl.check_restangle(json, json_len);
}

