#include "SoundPlayer.h"

using MoriorGames::SoundPlayer;

void SoundPlayer::playEffect(std::string file)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(file.c_str());
}

void SoundPlayer::playBackgroundMusic(std::string file)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(file.c_str());
}
