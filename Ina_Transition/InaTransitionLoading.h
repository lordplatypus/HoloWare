#ifndef INA_TRANSITION_LOADING_H_
#define INA_TRANSITION_LOADING_H_
#include "../Lib/GameObject.h"

class InaTransitionLoading : public GameObject
{
public:
    InaTransitionLoading(sf::Vector2f position, Scene* scene);
    ~InaTransitionLoading();
    void Update(float delta_time) override;
    void Draw() override;
    void ReactOnCollision(GameObject& other) override;

private:
    std::vector<int> letterSprites_;
    std::vector<float> scales_;
    float timer_{0.0f};
    int num_{0};
};

#endif