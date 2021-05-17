#ifndef BACKGROUND_PEOPLE_H_
#define BACKGROUND_PEOPLE_H_
#include "../Lib/GameObject.h"

class BackgroundPeople : public GameObject
{
public:
    BackgroundPeople(sf::Vector2f position, Scene* scene);
    ~BackgroundPeople();
    void Update(float delta_time) override;
    void Draw(sf::RenderWindow& render_window) const override;
    void SetOutcome(const bool& outcome);

private:
    void AnimationHandle(float delta_time);

private:
    std::vector<sf::Sprite> sprites_;

    int frame_{0};
    float timer_{0.0f};
    float maxTime_{0.0f};

    enum State{normal, hype};
    State state_{normal};
};

#endif