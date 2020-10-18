#ifndef CHICKEN_SPAWNER_H_
#define CHICKEN_SPAWNER_H_
#include "GameObject.h"
#include "MiniGame.h"

class ChickenSpawner : public GameObject
{
public:
    ChickenSpawner(MiniGame* mg);
    ~ChickenSpawner();
    void Update(float delta_time) override;
    void Draw() override;

private:
    MiniGame* mg_{nullptr};
    float timer_{5.0f};
    int chickenID_{0};
};

#endif