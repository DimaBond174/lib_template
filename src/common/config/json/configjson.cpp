/*
 * This is the source code of SpecNet project
 * It is licensed under MIT License.
 *
 * Copyright (c) Dmitriy Bondarenko
 * feel free to contact me: specnet.messenger@gmail.com
 */

#include "configjson.h"
#include "file/fileadapter.h"
#include "tools/specstatic.h"

ConfigJSON::ConfigJSON()
{}

// setPath  - where to load|save config
void ConfigJSON::set_paths(const std::string& in_exec_dir, const std::string& in_config_path)
{
  exec_dir = in_exec_dir;
  config_path = spec::toFullPath(in_config_path, exec_dir);
  return;
}

// try to save to path
void ConfigJSON::save()
{
  if (mapConfig.size())
  {
    std::string json("{");
    for (auto &&it : mapConfig)
    {
      json.append("\"").append(it.first).append("\":\"")
        .append(it.second).append("\",");
    }
    json[json.length()-1] = '}';
    spec::save_text(config_path.c_str(), json);
  }
  return ;
}

// try to load from path
bool ConfigJSON::load()
{
  bool re = false;
  try {
    const std::string &json = spec::read_text(config_path.c_str());
    uint32_t len = static_cast<uint32_t>(json.length());
    if (len > 3)
    {
      mapConfig.clear();
      SpecJson  specJson(json.c_str(), len, false);
      if (specJson.parse()) {
        traverse(specJson.getFirstNode());
        re = true;
      }
    }
  } catch(...) {}
  return re;
}

// try load from JSON, values will replace existing
bool ConfigJSON::load_json(const char *in_json,  uint32_t  json_size)
{
  bool re = false;
  if (json_size)
  {
    if (!json_size) json_size = static_cast<uint32_t>( strlen(in_json) );
    if (json_size > 3)
    {
      SpecJson  specJson(in_json, json_size, false);
      if (specJson.parse()) {
        traverse(specJson.getFirstNode());
        re = true;
      }
    }
  }
  return re;
}


bool ConfigJSON::if_new_in_update_json(const char *in_json,  int32_t  json_size)
{
  bool re = false;
  if (in_json)
  {
    if (!json_size) json_size = static_cast<int32_t>( strlen(in_json));
    if (json_size > 3)
    {
      SpecJson  specJson(in_json, static_cast<uint32_t>( json_size), false);
      if (specJson.parse()) {
        check_traverse(specJson.getFirstNode());
      }
    }
  }
  return re;
}

// try load from Dson, values will replace existing
bool ConfigJSON::load_dson(unsigned char  *dson,  uint32_t  dson_size)
{
  return false;
}

void ConfigJSON::setValue(const ConstString &key, uint32_t value)
{
  setValue(key, std::to_string(value));
  return;
}

void ConfigJSON::setValue(const ConstString &key, const std::string &value)
{
  mapConfig.insert_or_assign(std::string(key.c_str, key.size), value);
  return;
//  auto res = mapConfig.emplace(std::make_pair(key, value));
//  if (!res.second) mapConfig[key] = value;
//  isValid = true;
//  return;
}

void  ConfigJSON::traverse(TNode  *node) {
  TNode  *cur = node;
  while (cur) {
    switch (cur->type) {
    case 's':
    case 'd':
      if (cur->lenKey>0 && cur->lenData>0) {
//        mapConfig.insert(std::make_pair(
//          std::string(cur->pKey, cur->lenKey),
//          std::string(static_cast<const char *>(cur->pData), cur->lenData)));
        mapConfig.insert_or_assign(std::string(cur->pKey, cur->lenKey),
           std::string(static_cast<const char *>(cur->pData), cur->lenData));
      }
      break;
    case 'o':
      traverse(cur);
      break;
    case 'a':

      break;
    default:
      //std::cerr << "Error: ConfigJson::TNode->type=" << cur->type << std::endl;
      break;
    }
    cur = cur->nextNode;
  }
}


bool  ConfigJSON::check_traverse(TNode  *node) {
  bool re = false;
  TNode  *cur = node;
  while (cur) {
    switch (cur->type) {
    case 's':
    case 'd':
      if (cur->lenKey>0 && cur->lenData>0) {
        std::string  key(cur->pKey, cur->lenKey);
        std::string val(static_cast<const char *>(cur->pData), cur->lenData);
        auto &&it = mapConfig.find(key);
        if (it == mapConfig.end()  ||  0 != it->second.compare(val))
        {
          mapConfig.insert_or_assign(key, val);
          re = true;
        }
      }
      break;
    case 'o':
      re = check_traverse(cur);
      break;
    case 'a':

      break;
    default:
      //std::cerr << "Error: ConfigJson::TNode->type=" << cur->type << std::endl;
      break;
    }
    cur = cur->nextNode;
  }
  return re;
}


std::string  ConfigJSON::getStringValue(const ConstString &key) {
  auto&&  it_exists = mapConfig.find(key.c_str);
  if (it_exists != mapConfig.end()) {
    return  it_exists->second;
  }
  return std::string();
}

long long  ConfigJSON::getLongValue(const ConstString &key) {
  const std::string  &strVal = getStringValue(key);
  long long  re = 0;
  int  len = static_cast<int>( strVal.length() );
  if (len  >  0) {
    re = stoll(strVal.c_str(), len);
  }
  return re;
}

int  ConfigJSON::getIntValue(const ConstString &key)
{
  return static_cast<int>(getLongValue(key));
}

