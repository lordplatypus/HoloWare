#ifndef INA_TRANSITION_DOOR_CLOSE_H_
#define INA_TRANSITION_DOOR_CLOSE_H_
#include "../Lib/GameObject.h"
#include "../Lib/Math.h"
#include "../Lib/Camera.h"

class InaTransitionDoorClose : public GameObject
{
public:
    InaTransitionDoorClose(Camera* camera, Scene* scene, float scale = 1.0f);
    ~InaTransitionDoorClose();
    void Update(float delta_time) override;
    void Draw() override;

private:
    Camera* camera_{nullptr};
    Math math_;
    sf::Vector2f positionRight_{0.0f, 0.0f};
    sf::Vector2f positionLeft_{0.0f, 0.0f};
    sf::Vector2f endPositionRight_{0.0f, 0.0f};
    sf::Vector2f endPositionLeft_{0.0f, 0.0f};
    float scale_{1.0f};
    int spriteRight_{0};
    int spriteLeft_{0};
    float timer_{1.0f};
    bool thud_{false};
};

#endif