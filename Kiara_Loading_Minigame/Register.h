#ifndef REGISTER_H_
#define REGISTER_H_
#include "../Lib/GameObject.h"
#include "../Lib/ParticleManager.h"

class Register : public GameObject
{
public:
    Register(sf::Vector2f position, ParticleManager* pm, Scene* scene);
    ~Register();
    void Update(float delta_time) override;
    void Draw(sf::RenderWindow& render_window) const override;
    void SetOutcome(const bool& outcome);

private:
    void AnimationHandle(float delta_time);

private:
    ParticleManager* pm_{nullptr};

    std::vector<sf::Sprite> sprites_;

    int frame_{0};
    float timer_{0.0f};
    float maxTime_{0.0f};

    enum State{normal, hype};
    State state_{normal};
};

#endif