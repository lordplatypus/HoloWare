#ifndef KORONE_YUBI_MANAGER_H_
#define KORONE_YUBI_MANAGER_H_
#include "../Lib/Scene.h"

class KoroneYubiManager
{
public:
    KoroneYubiManager(Scene* scene);
    ~KoroneYubiManager();
    void Init();
    void SetActiveHand(const int handID);
    int GetActiveHand() const;
    void SetDifficulty(const int difficulty);
    int GetDificulty() const;
    void SetWin(const bool win);
    bool GetWin() const;

private:
    Scene* scene_{nullptr};
    int activeHand_{0};
    int difficulty_{0};
    bool win_{false};
};

#endif