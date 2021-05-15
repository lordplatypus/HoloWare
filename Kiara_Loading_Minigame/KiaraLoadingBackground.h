#ifndef KIARA_LOADING_BACKGROUND_H_
#define KIARA_LOADING_BACKGROUND_H_
#include "../Lib/GameObject.h"

class KiaraLoadingBackground : public GameObject
{
public:
    KiaraLoadingBackground(Scene* scene);
    ~KiaraLoadingBackground() override;
    void Draw(sf::RenderWindow& render_window) const override;
};

#endif