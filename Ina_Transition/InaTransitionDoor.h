#ifndef INA_TRANSITION_DOOR_H_
#define INA_TRANSITION_DOOR_H_
#include "../Lib/GameObject.h"
#include "../Lib/Math.h"

class InaTransitionDoor : public GameObject
{
public:
    InaTransitionDoor(sf::Vector2f position, sf::Vector2f endPosition, Scene* scene, float scale = 1.0f);
    ~InaTransitionDoor();
    void Update(float delta_time) override;
    void Draw(sf::RenderWindow& render_windoe) const override;
    void ReactOnCollision(GameObject& other) override;

private:
    Math math_;
    sf::Vector2f endPosition_{0.0f, 0.0f};
    float scale_{1.0f};
};

#endif