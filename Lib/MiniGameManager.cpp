#include "MiniGameManager.h"
#include "ID.h"

MiniGameManager::MiniGameManager()
{
    // SetDifficulty(easy_difficulty);
    // SetWin(false);
    // SetPlayCount(0);
    // SetHP(4);
    // SetTimerModifier(0.0f);
    Reset();
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

void MiniGameManager::SetOutcome(const bool outcome)
{
    outcome_ = outcome;
}

bool MiniGameManager::GetOutcome() const
{
    return outcome_;
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

void MiniGameManager::SetTimerModifier(const float modifier)
{
    timerModifier_ = modifier;
}

float MiniGameManager::GetTimerModifier() const
{
    return timerModifier_;
}

void MiniGameManager::Reset()
{
    SetDifficulty(easy_difficulty);
    SetOutcome(true);
    SetPlayCount(0);
    SetHP(4);
    SetTimerModifier(0.0f);
}