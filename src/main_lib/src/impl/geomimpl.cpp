/*
 * This is the source code of SpecNet project
 * It is licensed under MIT License.
 *
 * Copyright (c) Dmitriy Bondarenko
 * feel free to contact me: specnet.messenger@gmail.com
 */

#include "geomimpl.h"
#include "config/json/configjson.h"
#include <cmath>

void  GeomImpl::apply_settings(const char *json,  int  json_len)
{
  return;
}

static inline int64_t real_dist(int x1, int y1, int x2, int y2) {
  x1 -= x2;
  y1 -= y2;
  return std::llround(std::sqrt(x1 * x1  +  y1 * y1));
} // real_dist

int  GeomImpl::check_restangle(const char *json,  int  json_len)
{
  // temp json parser:
  int re = 0;
  //faux loop
  do {
    ConfigJSON parsed_json;
    if (!parsed_json.load_json(json, static_cast<uint32_t>(json_len)))  break;
    int x1 = parsed_json.getIntValue("x1");
    int y1 = parsed_json.getIntValue("y1");
    int x2 = parsed_json.getIntValue("x2");
    int y2 = parsed_json.getIntValue("y2");
    int x3 = parsed_json.getIntValue("x3");
    int y3 = parsed_json.getIntValue("y3");
    int x4 = parsed_json.getIntValue("x4");
    int y4 = parsed_json.getIntValue("y4");
    if (real_dist(x1, y1, x3, y3) == real_dist(x2, y2, x4, y4))
    {
      re  =  1;
    }
  } while (false);
  return re;
}
