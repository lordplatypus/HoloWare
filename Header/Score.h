#ifndef SCORE_H_
#define SCORE_H_
#include "GameObject.h"
//#include "MiniGame.h"

class Score : public GameObject
{
public:
    Score(sf::Vector2f position);
    ~Score();
    void Update(float delta_time) override;
    void Draw() override;

    void AddToScore(const int score);

private:
   // MiniGame* mg_{nullptr};
    int scoreText_{0};
    int scoreNum_{0};
};

#endif