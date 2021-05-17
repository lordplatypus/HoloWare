#ifndef ROCK_H_
#define ROCK_H_
#include "../Lib/GameObject.h"

class Rock : public GameObject
{
public:
    Rock(sf::Vector2f position, Scene* scene);
    ~Rock();
    void Update(float delta_time) override;
    void Draw(sf::RenderWindow& render_window) const override;
    void ReactOnCollision(GameObject& other) override;

private:
    float angle_{0.0f};
    float angleVelocity_{0.0f};
};

#endif