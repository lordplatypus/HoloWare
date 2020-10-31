#ifndef INA_TRANSITION_TIMER_H_
#define INA_TRANSITION_TIMER_H_
#include "GameObject.h"
#include "Camera.h"

class InaTransitionTimer : public GameObject
{
public:
    InaTransitionTimer(sf::Vector2f position, float sec, Camera* camera, Scene* scene, float scale = 1.0f);
    ~InaTransitionTimer();
    void Update(float delta_time) override;
    void Draw() override;

private:
    Camera* camera_{nullptr};
    float scale_{1.0f};
    float sec_{0};
    float timer_{1.0f};
    int end_{0};
    int bomb_{0};
    int explosion_{0};
    std::vector<int> segments_;

    bool deathSequence_{false};
};

#endif