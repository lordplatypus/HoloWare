#include "Score.h"
#include "../Lib/LP.h"

Score::Score()
{
    scoreText_ = LP::SetText(std::to_string(scoreNum_), position_, 64);
    scoreText_.setScale(0.2f, 0.2f);
}

Score::~Score()
{}

void Score::Draw(sf::RenderWindow& render_window) const
{
    render_window.draw(scoreText_);
}

void Score::AddToScore(const int score)
{
    scoreNum_ += score;
    scoreText_.setString(std::to_string(scoreNum_));
}

void Score::SetPosition(const sf::Vector2f& position)
{
    position_ = position;
    scoreText_.setPosition(position_);
}