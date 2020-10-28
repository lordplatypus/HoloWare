#include "../Header/MiniGameManager.h"
#include "../Header/ID.h"

MiniGameManager::MiniGameManager()
{
    SetDifficulty(easy_difficulty);
    SetWin(false);
    SetPlayCount(0);
    SetHP(4);
}

MiniGameManager::~MiniGameManager()
{}

void MiniGameManager::SetDifficulty(const int difficulty)
{
    difficulty_ = difficulty;
}

int MiniGameManager::GetDifficulty() const
{
    return difficulty_;
}

void MiniGameManager::SetWin(const bool win)
{
    win_ = win;
}

bool MiniGameManager::GetWin() const
{
    return win_;
}

void MiniGameManager::SetPlayCount(const int winCount)
{
    playCount_ = winCount;
}

void MiniGameManager::IncrementPlayCount()
{
    playCount_++;
}

int MiniGameManager::GetPlayCount() const
{
    return playCount_;
}

void MiniGameManager::SetHP(const int HP)
{
    HP_ = HP;
}

int MiniGameManager::GetHP() const
{
    return HP_;
}

void MiniGameManager::DecrementHP()
{
    HP_--;
}

void MiniGameManager::Reset()
{
    SetDifficulty(easy_difficulty);
    SetWin(false);
    SetPlayCount(0);
    SetHP(4);
}