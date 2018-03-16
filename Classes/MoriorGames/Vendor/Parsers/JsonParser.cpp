#include "JsonParser.h"

using MoriorGames::JsonParser;

JsonParser::JsonParser(std::string json)
{
    document.Parse(json.c_str());
    assert(document.IsObject());
}

int JsonParser::getInt(const rapidjson::Value &data, std::string key)
{
    return (data.HasMember(key.c_str()) && data[key.c_str()].IsInt()) ?
           data[key.c_str()].GetInt() : 0;
}

long int JsonParser::getInt64(const rapidjson::Value &data, std::string key)
{
    return (data.HasMember(key.c_str()) && data[key.c_str()].IsInt64()) ?
           data[key.c_str()].GetInt64() : 0;
}

double JsonParser::getDouble(const rapidjson::Value &data, std::string key)
{
    return (data.HasMember(key.c_str()) && (data[key.c_str()].IsDouble() || data[key.c_str()].IsInt())) ?
           data[key.c_str()].GetDouble() : 0;
}

std::string JsonParser::getString(const rapidjson::Value &data, std::string key)
{
    return (data.HasMember(key.c_str()) && data[key.c_str()].IsString()) ?
           data[key.c_str()].GetString() : "";
}

bool JsonParser::getBool(const rapidjson::Value &data, std::string key)
{
    return (data.HasMember(key.c_str()) && data[key.c_str()].IsBool()) ?
           data[key.c_str()].GetBool() : false;
}
