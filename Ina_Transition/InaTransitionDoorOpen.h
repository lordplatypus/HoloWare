#ifndef INA_TRANSITION_DOOR_OPEN_H_
#define INA_TRANSITION_DOOR_OPEN_H_
#include "../Lib/GameObject.h"
#include "../Lib/Math.h"
#include "../Lib/Camera.h"

class InaTransitionDoorOpen : public GameObject
{
public:
    InaTransitionDoorOpen(Scene* scene);
    ~InaTransitionDoorOpen();
    void Update(float delta_time) override;
    void Draw(sf::RenderWindow& render_window) const override;

private:
    Math math_;
    sf::Vector2f positionRight_{0.0f, 0.0f};
    sf::Vector2f positionLeft_{0.0f, 0.0f};
    sf::Vector2f endPositionRight_{0.0f, 0.0f};
    sf::Vector2f endPositionLeft_{0.0f, 0.0f};
    sf::Sprite spriteRight_;
    sf::Sprite spriteLeft_;
    float timer_{1.0f};
};

#endif