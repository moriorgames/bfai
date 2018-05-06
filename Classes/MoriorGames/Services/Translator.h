#ifndef MORIOR_GAMES_SERVICES_TRANSLATOR_H
#define MORIOR_GAMES_SERVICES_TRANSLATOR_H

#include "cocos2d.h"
#include <string>
#include <vector>
#include "../Vendor/Parsers/json/document.h"

USING_NS_CC;
using namespace rapidjson;

/**
 * How to use it:
 *
 * auto translator = new Translator(LANGUAGE);
 * auto translate = translator->tr("general_loading");
 * auto translate = translator->tr("general_welcome", "Jaimie");
 */
class Translator
{
public:
    const std::string DEFAULT_LANGUAGE = "en";

    explicit Translator(std::string language);
    std::string tr(std::string key, std::string s = "");
    std::string tr(std::string key, int integer);
    static std::string getLanguageCode();

private:
    std::string language;
    Document document;
};

#endif
