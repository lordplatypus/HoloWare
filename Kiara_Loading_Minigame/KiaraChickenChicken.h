#ifndef KIARA_CHICKEN_CHICKEN_H_
#define KIARA_CHICKEN_CHICKEN_H_
#include "../Lib/GameObject.h"

class KiaraChickenChicken : public GameObject
{
public:
    KiaraChickenChicken(sf::Vector2f position, Scene* scene);
    ~KiaraChickenChicken();
    void Update(float delta_time) override;
    void Draw() override;
    void ReactOnCollision(GameObject& other) override;

private:
    float angle_{0.0f};
    float angleVelocity_{0.0f};
};

#endif