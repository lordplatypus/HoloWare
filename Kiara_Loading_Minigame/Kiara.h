#ifndef KIARA_H_
#define KIARA_H_
#include "../Lib/GameObject.h"
#include "../Lib/ParticleManager.h"
#include "Score.h"

class Kiara : public GameObject
{
public:
    Kiara(const sf::Vector2f& position, int difficulty, ParticleManager* pm, Scene* scene);
    ~Kiara();
    void Update(float delta_time) override;
    void Draw(sf::RenderWindow& render_window) const override;
    void ReactOnCollision(GameObject& other) override;

private:
    void InputHandle(float delta_time);
    void AnimationHandle(float delta_time);
    void StunHandle(float delta_time);

private:
    ParticleManager* pm_{nullptr};

    //Sprites
    std::vector<sf::Sprite> kiaraSprite_;
    std::vector<sf::Sprite> bucketSprite_;
    sf::Sprite shadowSprite_;

    //for animation
    int frame_{0};
    float timer_{0.0f};

    //Bucket / winning condition
    int chickenCount_{0};
    int difficulty_{0};

    //Stun
    bool stun_{false};
    float stunTimer_{0.0f};
    bool blink_{false};
    float blinkTimer_{0.0f};

    //Score
    Score score_;
};

#endif