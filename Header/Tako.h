#ifndef TAKO_H_
#define TAKO_H_
#include "GameObject.h"
#include "Math.h"

class Tako : public GameObject
{
public:
    Tako(sf::Vector2f position, Scene* scene);
    ~Tako();
    void Update(float delta_time) override;
    void Draw() override;
    void ReactOnCollision(GameObject& other) override;

private:
    void AnimationHandle(float delta_time);
    void ScaleHandle(float delta_time);

private:
    Math math_;

    //Sprites
    std::vector<int> takoSprite_{};

    //for animation
    int frame_{0};
    float timer_{0.0f};
    float scale_{1.0f};
    float scaleTimer_{0.0};
    float angle_{-45.0f};
    float endAngle_{45.0f};
};

#endif