#ifndef MORIOR_GAMES_SERVICES_STRING_FILE_READER_H
#define MORIOR_GAMES_SERVICES_STRING_FILE_READER_H

#include "cocos2d.h"
USING_NS_CC;

namespace MoriorGames {

class StringFileReader
{
public:
    std::string getStringFromFile(std::string file);
};

}

#endif
