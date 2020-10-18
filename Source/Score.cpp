#include "../Header/Score.h"
#include "../Header/LP.h"

Score::Score(sf::Vector2f position)
{
//mg_ = mg;
    tag_ = "Score";
    name_ = "Score";
    position_ = position;

    scoreText_ = LP::SetText(std::to_string(scoreNum_), position_, 64);
}

Score::~Score()
{
    LP::DeleteText(scoreText_);
}

void Score::Update(float delta_time)
{}

void Score::Draw()
{
    LP::DrawText(scoreText_);
}

void Score::AddToScore(const int score)
{
    scoreNum_ += score;
    LP::SetTextString(scoreText_, std::to_string(scoreNum_));
}