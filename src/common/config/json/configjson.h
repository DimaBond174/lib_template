/*
 * This is the source code of SpecNet project
 * It is licensed under MIT License.
 *
 * Copyright (c) Dmitriy Bondarenko
 * feel free to contact me: specnet.messenger@gmail.com
 */

#ifndef ConfigJSON_H
#define ConfigJSON_H
#pragma once
#include <string>
#include <map>
#include "i/iconfig.h"
#include "tools/specjson.h"

class ConfigJSON : public IConfig
{
public:
  // setPath  - where to load|save config
  void set_paths(const std::string& in_exec_dir, const std::string& in_config_path) override;
  // try to save to path
  void save() override;
  // try to load from path
  bool load() override;
  // try load from JSON, values will replace existing
  bool load_json(const char *in_json,  uint32_t  json_size) override;
  // try load from Dson, values will replace existing
  bool load_dson(unsigned char  *in_dson,  uint32_t  dson_size) override;
  // update current Dson, return true is something new found
  bool if_new_in_update_json(const char *in_json,  int32_t  json_size);

// float you can store in minor ed: 1.23 -> 123
  int  getIntValue(const ConstString &key) override;
  long long  getLongValue(const ConstString &key) override;
  std::string  getStringValue(const ConstString &key) override;
  void setValue(const ConstString &key, const std::string &value) override;
  void setValue(const ConstString &key, uint32_t value) override;

  ConfigJSON();
  virtual ~ConfigJSON() {}
  
protected:
  std::map<std::string, std::string>  mapConfig;
  virtual void  traverse(TNode  *node);  
  bool  check_traverse(TNode  *node);
};

#endif //ConfigJSON_H
