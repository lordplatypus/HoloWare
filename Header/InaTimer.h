#ifndef INA_TIMER_H_
#define INA_TIMER_H_
#include "GameObject.h"

class InaTimer : public GameObject
{
public:
    InaTimer(sf::Vector2f position, int sec, float scale, Scene* scene);
    ~InaTimer();
    void Update(float delta_time) override;
    void Draw() override;

private:
    int sec_{0};
    float timer_{1.0f};
    int end_{0};
    int bomb_{0};
    std::vector<int> segments_;
};

#endif