#ifndef KIARA_CHICKEN_POINTS_H_
#define KIARA_CHICKEN_POINTS_H_
#include "../Lib/GameObject.h"

class KiaraChickenPoints : public GameObject
{
public:
    KiaraChickenPoints(sf::Vector2f position, Scene* scene);
    ~KiaraChickenPoints();
    void Update(float delta_time) override;
    void Draw(sf::RenderWindow& render_window) const override;

private:
    sf::Text text_;
    int alpha_{255};
    float timer_{0.005f};
};

#endif