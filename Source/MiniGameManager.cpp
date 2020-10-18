#include "../Header/MiniGameManager.h"
#include "../Header/MiniGameNull.h"
#include "../Header/ID.h"
#include "../Header/MiniGameKiara.h"

static MiniGameNull nullMiniGame_;

MiniGameManager::MiniGameManager() : miniGame_{&nullMiniGame_}
{}

MiniGameManager::~MiniGameManager()
{
    delete miniGame_;
}

void MiniGameManager::StartMiniGame(const int miniGame)
{
    SetClear(false);
    if (miniGame == kiara_minigame)
    {
        miniGame_ = new MiniGameKiara();
        SetTimer(10.0f);
    }
}

void MiniGameManager::Update(float delta_time)
{
    miniGame_->Update(delta_time);
    Timer(delta_time);
}

void MiniGameManager::Draw()
{
    miniGame_->Draw();
}

void MiniGameManager::EndMiniGame()
{
    SetClear(miniGame_->IsClear());
    delete miniGame_;
    miniGame_ = &nullMiniGame_;
}

float MiniGameManager::GetTimer() const
{
    return timer_;
}

bool MiniGameManager::GetClear() const
{
    return clear_;
}

void MiniGameManager::SetTimer(const float time)
{
    timer_ = time;
}

void MiniGameManager::Timer(float delta_time)
{
    if (timer_ > 0.0f) timer_ -= delta_time;
}

void MiniGameManager::SetClear(const bool clear)
{
    clear_ = clear;
}