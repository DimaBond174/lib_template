/*
 * This is the source code of SpecNet project
 * It is licensed under MIT License.
 *
 * Copyright (c) Dmitriy Bondarenko
 * feel free to contact me: specnet.messenger@gmail.com
 */

#ifndef ICONFIG_H
#define ICONFIG_H

#include <string>
#include "tools/specstatic.h"

class  IConfig  {
 public:
  virtual ~IConfig()  {  }

  // setPath  - where to load|save config
  virtual void set_paths(const std::string& in_exec_dir, const std::string& in_config_path) = 0;
  // try to save to path
  virtual void save() = 0;
  // try to load from path
  virtual bool load() = 0;
  // try load from JSON, values will replace existing
  virtual bool load_json(const char *in_json,  uint32_t  json_size) = 0;
  // try load from Dson, values will replace existing
  virtual bool load_dson(unsigned char  *in_dson,  uint32_t  dson_size) = 0;

// float you can store in minor ed: 1.23 -> 123
  virtual int  getIntValue(const ConstString &key)  =  0;
  virtual long long  getLongValue(const ConstString &key)  =  0;
  virtual std::string  getStringValue(const ConstString &key)  =  0;
  virtual void setValue(const ConstString &key, const std::string &value) = 0;
  virtual void setValue(const ConstString &key, uint32_t value) = 0;

  std::string config_path; // where to save|load
  std::string exec_dir; // where executive to replace ./ -> fullpath
};
#endif // ICONFIG_H
