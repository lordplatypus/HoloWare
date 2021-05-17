#ifndef SCORE_H_
#define SCORE_H_
#include <SFML/Graphics.hpp>

class Score
{
public:
    Score();
    ~Score();
    void Draw(sf::RenderWindow& render_window) const;
    void AddToScore(const int score);
    void SetPosition(const sf::Vector2f& position);

private:
    sf::Vector2f position_{0.0f, 0.0f};
    sf::Text scoreText_;
    int scoreNum_{0};
};

#endif