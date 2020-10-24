#ifndef INA_DOOR_H_
#define INA_DOOR_H_
#include "GameObject.h"
#include "Math.h"

class InaDoor : public GameObject
{
public:
    InaDoor(sf::Vector2f position, sf::Vector2f endPosition, Scene* scene, float scale = 1.0f);
    ~InaDoor();
    void Update(float delta_time) override;
    void Draw() override;
    void ReactOnCollision(GameObject& other) override;

private:
    Math math_;
    sf::Vector2f endPosition_{0.0f, 0.0f};
    float scale_{1.0f};
};

#endif