#ifndef KIARA_CHICKEN_SPAWNER_H_
#define KIARA_CHICKEN_SPAWNER_H_
#include "GameObject.h"

class KiaraChickenSpawner : public GameObject
{
public:
    KiaraChickenSpawner(Scene* scene);
    ~KiaraChickenSpawner();
    void Update(float delta_time) override;
    void Draw() override;

private:
    float timer_{5.0f};
    int chickenID_{0};
};

#endif