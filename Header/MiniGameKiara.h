#ifndef MINI_GAME_KIARA_H_
#define MINI_GAME_KIARA_H_
#include "MiniGame.h"

class MiniGameKiara : public MiniGame
{
public:
    MiniGameKiara();
    ~MiniGameKiara();
    virtual void Update(float delta_time) override;
    virtual void Draw() override;

private:
    int background_{0};
};

#endif