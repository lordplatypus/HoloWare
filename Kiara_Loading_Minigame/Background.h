#ifndef BACKGROUND_H_
#define BACKGROUND_H_
#include "../Lib/GameObject.h"

class Background : public GameObject
{
public:
    Background(Scene* scene);
    ~Background() override;
    void Draw(sf::RenderWindow& render_window) const override;
};

#endif