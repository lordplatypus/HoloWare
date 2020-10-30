#include "../Header/KiaraChickenScore.h"
#include "../Header/LP.h"

KiaraChickenScore::KiaraChickenScore(sf::Vector2f position)
{
    position_ = position;
    scoreText_ = LP::SetText(std::to_string(scoreNum_), position_, 64);
}

KiaraChickenScore::~KiaraChickenScore()
{
    LP::DeleteText(scoreText_);
}

void KiaraChickenScore::Draw()
{
    LP::DrawText(scoreText_);
}

void KiaraChickenScore::AddToScore(const int score)
{
    scoreNum_ += score;
    LP::SetTextString(scoreText_, std::to_string(scoreNum_));
}