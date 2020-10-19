#ifndef SCORE_H_
#define SCORE_H_
#include <SFML/Graphics.hpp>

class Score
{
public:
    Score(sf::Vector2f position);
    ~Score();
    void Draw();
    void AddToScore(const int score);

private:
    sf::Vector2f position_{0.0f, 0.0f};
    int scoreText_{0};
    int scoreNum_{0};
};

#endif