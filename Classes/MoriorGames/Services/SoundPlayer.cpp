#include "SoundPlayer.h"
#include "../Definitions.h"

using MoriorGames::SoundPlayer;

void SoundPlayer::playEffect(std::string file)
{
    if (MODE_SOUND) {
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(file.c_str());
    }
}

void SoundPlayer::playBackgroundMusic(std::string file)
{
    if (MODE_SOUND) {
        CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(file.c_str(), true);
    }
}
