#ifndef MINI_GAME_MANAGER_H_
#define MINI_GAME_MANAGER_H_
#include "MiniGame.h"

class MiniGameManager
{
public:
    MiniGameManager();
    ~MiniGameManager();
    void StartMiniGame(const int miniGame);
    void Update(float delta_time);
    void Draw();
    void EndMiniGame();

    float GetTimer() const;
    bool GetClear() const;

private:
    void SetTimer(const float time);
    void Timer(float delta_time);
    void SetClear(const bool clear);

private:
    MiniGame* miniGame_{nullptr};
    float timer_{0.0f};
    bool clear_{false};
};

#endif