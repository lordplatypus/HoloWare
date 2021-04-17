#ifndef KIARA_CHICKEN_ROCK_H_
#define KIARA_CHICKEN_ROCK_H_
#include "../Lib/GameObject.h"

class KiaraChickenRock : public GameObject
{
public:
    KiaraChickenRock(sf::Vector2f position, Scene* scene);
    ~KiaraChickenRock();
    void Update(float delta_time) override;
    void Draw() override;
    void ReactOnCollision(GameObject& other) override;

private:
    float angle_{0.0f};
    float angleVelocity_{0.0f};
};

#endif