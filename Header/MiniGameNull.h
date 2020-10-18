#ifndef MINI_GAME_NULL_H_
#define MINI_GAME_NULL_H_
#include "MiniGame.h"

class MiniGameNull : public MiniGame
{
public:
    virtual void Update(float delta_time) override {}
    virtual void Draw() override {}
};

#endif