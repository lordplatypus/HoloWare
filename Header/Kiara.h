#ifndef KIARA_H_
#define KIARA_H_
#include "GameObject.h"
#include "Score.h"
#include "MiniGame.h"

class Kiara : public GameObject
{
public:
    Kiara(sf::Vector2f position, MiniGame* mg);
    ~Kiara();
    void Update(float delta_time) override;
    void Draw() override;
    void ReactOnCollision(GameObject& other) override;

private:
    void InputHandle(float delta_time);
    void AnimationHandle(float delta_time);

private:
    MiniGame* mg_{nullptr};
    //Sprites
    std::vector<int> playerSprite_;
    int shadowSprite_{0};

    //for animation
    int frame_{0};
    float timer_{0.0f};

    //Score
    Score* score_{nullptr};
};

#endif