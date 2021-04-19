#ifndef KIARA_CHICKEN_SCORE_H_
#define KIARA_CHICKEN_SCORE_H_
#include <SFML/Graphics.hpp>

class KiaraChickenScore
{
public:
    KiaraChickenScore();
    ~KiaraChickenScore();
    void Draw(sf::RenderWindow& render_window) const;
    void AddToScore(const int score);
    void SetPosition(const sf::Vector2f& position);

private:
    sf::Vector2f position_{0.0f, 0.0f};
    sf::Text scoreText_;
    int scoreNum_{0};
};

#endif