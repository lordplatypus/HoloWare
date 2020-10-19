#ifndef CHICKEN_SPAWNER_H_
#define CHICKEN_SPAWNER_H_
#include "GameObject.h"

class ChickenSpawner : public GameObject
{
public:
    ChickenSpawner(Scene* scene);
    ~ChickenSpawner();
    void Update(float delta_time) override;
    void Draw() override;

private:
    float timer_{5.0f};
    int chickenID_{0};
};

#endif