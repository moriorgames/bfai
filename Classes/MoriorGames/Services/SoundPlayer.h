#ifndef MORIOR_GAMES_SERVICES_SOUND_PLAYER_H
#define MORIOR_GAMES_SERVICES_SOUND_PLAYER_H

#include <string>
#include "SimpleAudioEngine.h"

class SoundPlayer
{
public:
    static void playEffect(std::string file);
    static void playBackgroundMusic(std::string file);
};

#endif
