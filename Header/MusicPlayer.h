#ifndef MUSIC_PLAYER_H_
#define MUSIC_PLAYER_H_
#include <SFML/Audio.hpp>
#include <unordered_map>

class MusicPlayer
{
public:
    MusicPlayer();
    ~MusicPlayer();
    void PlayMusic(const int musicID, const bool loop);

private:
    std::unordered_map<int, sf::Music> music_;
};

#endif