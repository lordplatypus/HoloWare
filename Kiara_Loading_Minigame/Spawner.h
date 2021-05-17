#ifndef SPAWNER_H_
#define SPAWNER_H_
#include "../Lib/GameObject.h"

class Spawner : public GameObject
{
public:
    Spawner(int difficulty, Scene* scene);
    ~Spawner();
    void Update(float delta_time) override;

private:
    void ChooseObjectToSpawn();

private:
    float timer_{1.0f};
    int difficulty_{0};
    int odds_{0};
};

#endif