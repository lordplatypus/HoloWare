#ifndef MINI_GAME_MANAGER_H_
#define MINI_GAME_MANAGER_H_

class MiniGameManager
{
public:
    MiniGameManager();
    ~MiniGameManager();
    void SetDifficulty(const int difficulty);
    int GetDifficulty() const;
    void SetOutcome(const bool outcome);
    bool GetOutcome() const;
    void SetPlayCount(const int winCount);
    void IncrementPlayCount();
    int GetPlayCount() const;
    void SetHP(const int HP);
    void DecrementHP();
    int GetHP() const;
    void SetTimerModifier(const float modifier);
    float GetTimerModifier() const;

    void Reset();

private:
    int difficulty_{0};
    bool outcome_{true};
    int playCount_{0};
    int HP_{0};
    float timerModifier_{0.0f};
};

#endif