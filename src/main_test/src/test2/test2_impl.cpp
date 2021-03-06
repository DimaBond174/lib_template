/*
 * This is the source code of SpecNet project
 * It is licensed under MIT License.
 *
 * Copyright (c) Dmitriy Bondarenko
 * feel free to contact me: specnet.messenger@gmail.com
 */

#define BUILDING_Test2Lib
#include "test2_impl.h"
#include <iostream>
#include "file/fileadapter.h"
#include "config/json/configjson.h"
#include "geomlib.h"
#if defined (Linux)
#include "system/linux/linuxsystem.h"
#else
#include "system/windows/windowssystem.h"
#endif

int do_Test2()
{
  int re = 0;
  //faux loop
  do {
    const std::string &exec_dir = spec::getExePath();
    const std::string &test_json_file = spec::toFullPath("./test_assets/test2.json", exec_dir);
    const std::string &test_json = spec::read_text(test_json_file.c_str());
    if (test_json.empty())
    {
      std::cerr << "Can't read test file: " << test_json_file;
      break;
    }
    if (0 ==  check_restangle(test_json.c_str(),  test_json.size()))
    {
      re = 1;
    }
  } while (false);
  return re;
}
