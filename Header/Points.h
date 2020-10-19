#ifndef POINTS_H_
#define POINTS_H_
#include "GameObject.h"

class  Points : public GameObject
{
public:
     Points(sf::Vector2f position, Scene* scene);
    ~ Points();
    void Update(float delta_time) override;
    void Draw() override;

private:
    int text_{0};
    int alpha_{255};
    float timer_{0.005f};
};

#endif