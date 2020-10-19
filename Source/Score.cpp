#include "../Header/Score.h"
#include "../Header/LP.h"

Score::Score(sf::Vector2f position)
{
    position_ = position;
    scoreText_ = LP::SetText(std::to_string(scoreNum_), position_, 64);
}

Score::~Score()
{
    LP::DeleteText(scoreText_);
}

void Score::Draw()
{
    LP::DrawText(scoreText_);
}

void Score::AddToScore(const int score)
{
    scoreNum_ += score;
    LP::SetTextString(scoreText_, std::to_string(scoreNum_));
}