#include "Translator.h"
#include "../Vendor/Utils/TextUtils.h"
#include <fstream>
#include <sstream>
#include <iostream>

Translator::Translator(std::string language)
    : language{language}
{
    std::string jsonFile = "data/messages." + language + ".json";
    auto fileUtils = FileUtils::getInstance();
    auto fullPath = fileUtils->fullPathForFilename(jsonFile);

    if (fileUtils->isFileExist(fullPath)) {

        auto json = fileUtils->getStringFromFile(fullPath);
        document.Parse(json.c_str());
        assert(document.IsObject());

    } else {

        jsonFile = "data/messages." + DEFAULT_LANGUAGE + ".json";
        fullPath = fileUtils->fullPathForFilename(jsonFile);
        auto json = fileUtils->getStringFromFile(fullPath);
        document.Parse(json.c_str());
        assert(document.IsObject());
    }
}

std::string Translator::tr(std::string key, std::string s)
{
    std::string translation = key;

    if (document.HasMember(key.c_str())) {

        translation = document[key.c_str()].GetString();

        const char *literal = document[key.c_str()].GetString();
        char *buf;
        size_t sz;
        sz = snprintf(NULL, 0, literal, s.c_str());
        buf = (char *) malloc(sz + 1);
        snprintf(buf, sz + 1, literal, s.c_str());
        translation = buf;

    }

    return translation;
}

std::string Translator::tr(std::string key, int integer)
{
    std::string translation = key;

    if (document.HasMember(key.c_str())) {

        translation = document[key.c_str()].GetString();

        const char *literal = document[key.c_str()].GetString();
        char *buf;
        size_t sz;
        std::string s = to_string(integer);
        sz = snprintf(NULL, 0, literal, s.c_str());
        buf = (char *) malloc(sz + 1);
        snprintf(buf, sz + 1, literal, s.c_str());
        translation = buf;

    }

    return translation;
}

std::string Translator::getLanguageCode()
{
    std::string deviceLanguage = Application::getInstance()->getCurrentLanguageCode();

    if (deviceLanguage != "en" && deviceLanguage != "es") {
        deviceLanguage = "en";
    }

    return deviceLanguage;
}
