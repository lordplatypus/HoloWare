#ifndef KIARA_CHICKEN_KIARA_H_
#define KIARA_CHICKEN_KIARA_H_
#include "../Lib/GameObject.h"
#include "KiaraChickenScore.h"

class KiaraChickenKiara : public GameObject
{
public:
    KiaraChickenKiara(sf::Vector2f position, Scene* scene);
    ~KiaraChickenKiara();
    void Update(float delta_time) override;
    void Draw(sf::RenderWindow& render_window) const override;
    void ReactOnCollision(GameObject& other) override;

private:
    void InputHandle(float delta_time);
    void AnimationHandle(float delta_time);
    void StunHandle(float delta_time);

private:
    //Sprites
    std::vector<sf::Sprite> playerSprite_;
    sf::Sprite shadowSprite_;

    //for animation
    int frame_{0};
    float timer_{0.0f};

    //Stun
    bool stun_{false};
    float stunTimer_{0.0f};
    bool blink_{false};
    float blinkTimer_{0.0f};

    //Score
    KiaraChickenScore score_;
};

#endif