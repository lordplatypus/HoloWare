#ifndef INA_TRANSITION_TIMER_H_
#define INA_TRANSITION_TIMER_H_
#include "../Lib/GameObject.h"
#include "../Lib/Camera.h"

class InaTransitionTimer : public GameObject
{
public:
    InaTransitionTimer(sf::Vector2f position, float sec, Scene* scene);
    ~InaTransitionTimer();
    void Update(float delta_time) override;
    void Draw(sf::RenderWindow& render_window) const override;

private:
    float sec_{0};
    float timer_{1.0f};
    sf::Sprite end_;
    sf::Sprite bomb_;
    sf::Sprite explosion_;
    std::vector<sf::Sprite> segments_;
    sf::Vector2f scale_{0.5f, 0.5f};

    bool deathSequence_{false};
};

#endif