#include "../Header/KoroneYubiManager.h"

KoroneYubiManager::KoroneYubiManager(Scene* scene) : scene_{scene}
{}

KoroneYubiManager::~KoroneYubiManager()
{}

void KoroneYubiManager::Init()
{
    activeHand_ = 0;
}

void KoroneYubiManager::SetActiveHand(const int handID)
{
    activeHand_ = handID;
    if (activeHand_ > GetDificulty()) SetWin(true);
}

int KoroneYubiManager::GetActiveHand() const
{
    return activeHand_;
}

void KoroneYubiManager::SetDifficulty(const int difficulty)
{
    difficulty_ = difficulty;
}

int KoroneYubiManager::GetDificulty() const
{
    return difficulty_;
}

void KoroneYubiManager::SetWin(const bool win)
{
    win_ = win;
    if (win_) scene_->OnWin();
}

bool KoroneYubiManager::GetWin() const
{
    return win_;
}