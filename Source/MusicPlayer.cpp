#include "../Header/MusicPlayer.h"
#include "../Header/ID.h"

MusicPlayer::MusicPlayer()
{
    music_[kiara_theme].openFromFile("./Resource/Kiara/Kiara_Loading_Song.ogg");
}

MusicPlayer::~MusicPlayer()
{}

void MusicPlayer::PlayMusic(const int musicID, const bool loop)
{
    music_[musicID].setLoop(loop);
    music_[musicID].play();
}