#ifndef POINTS_H_
#define POINTS_H_
#include "../Lib/GameObject.h"

class Points : public GameObject
{
public:
    Points(sf::Vector2f position, Scene* scene);
    ~Points();
    void Update(float delta_time) override;
    void Draw(sf::RenderWindow& render_window) const override;

private:
    sf::Text text_;
    int alpha_{255};
    float timer_{0.005f};
};

#endif