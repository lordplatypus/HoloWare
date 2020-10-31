#ifndef KIARA_CHICKEN_SPAWNER_H_
#define KIARA_CHICKEN_SPAWNER_H_
#include "GameObject.h"

class KiaraChickenSpawner : public GameObject
{
public:
    KiaraChickenSpawner(int difficulty, Scene* scene);
    ~KiaraChickenSpawner();
    void Update(float delta_time) override;

private:
    void ChooseObjectToSpawn();

private:
    float timer_{1.0f};
    int difficulty_{0};
    int odds_{0};
};

#endif