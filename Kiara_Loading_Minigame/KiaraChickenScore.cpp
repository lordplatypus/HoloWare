#include "KiaraChickenScore.h"
#include "../Lib/LP.h"

KiaraChickenScore::KiaraChickenScore()
{
    scoreText_ = LP::SetText(std::to_string(scoreNum_), position_, 64);
}

KiaraChickenScore::~KiaraChickenScore()
{}

void KiaraChickenScore::Draw(sf::RenderWindow& render_window) const
{
    render_window.draw(scoreText_);
}

void KiaraChickenScore::AddToScore(const int score)
{
    scoreNum_ += score;
    scoreText_.setString(std::to_string(scoreNum_));
}

void KiaraChickenScore::SetPosition(const sf::Vector2f& position)
{
    position_ = position;
}