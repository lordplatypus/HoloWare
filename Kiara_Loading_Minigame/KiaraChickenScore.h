#ifndef KIARA_CHICKEN_SCORE_H_
#define KIARA_CHICKEN_SCORE_H_
#include <SFML/Graphics.hpp>

class KiaraChickenScore
{
public:
    KiaraChickenScore(sf::Vector2f position);
    ~KiaraChickenScore();
    void Draw();
    void AddToScore(const int score);

private:
    sf::Vector2f position_{0.0f, 0.0f};
    int scoreText_{0};
    int scoreNum_{0};
};

#endif