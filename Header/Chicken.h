#ifndef CHICKEN_H_
#define CHICKEN_H_
#include "GameObject.h"
#include "MiniGame.h"

class Chicken : public GameObject
{
public:
    Chicken(sf::Vector2f position, MiniGame* mg);
    ~Chicken();
    void Update(float delta_time) override;
    void Draw() override;
    void ReactOnCollision(GameObject& other) override;

private:
    MiniGame* mg_{nullptr};
    float angle_{0.0f};
    float angleVelocity_{0.0f};
};

#endif