#ifndef INA_TRANSITION_HP_H_
#define INA_TRANSITION_HP_H_
#include "../Lib/GameObject.h"
#include "../Lib/Math.h"

class InaTransitionHP : public GameObject
{
public:
    InaTransitionHP(sf::Vector2f position, Scene* scene);
    ~InaTransitionHP();
    void Update(float delta_time) override;
    void Draw(sf::RenderWindow& render_window) const override;
    void ReactOnCollision(GameObject& other) override;

private:
    void AnimationHandle(float delta_time);
    void ScaleHandle(float delta_time);

private:
    Math math_;

    //Sprites
    std::vector<sf::Sprite> takoSprite_;

    //for animation
    int frame_{0};
    float timer_{0.0f};
    float scale_{1.0f};
    float scaleTimer_{0.0};
    float angle_{-45.0f};
    float endAngle_{45.0f};
};

#endif