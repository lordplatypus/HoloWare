#ifndef INA_LOADING_H_
#define INA_LOADING_H_
#include "GameObject.h"

class InaLoading : public GameObject
{
public:
    InaLoading(sf::Vector2f position, Scene* scene);
    ~InaLoading();
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