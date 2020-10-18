#include "../Header/ChickenSpawner.h"
#include "../Header/Chicken.h"

ChickenSpawner::ChickenSpawner(MiniGame* mg) : mg_{mg}
{
    tag_ = "Spawner";
    name_ = "ChickenSpawner";
}

ChickenSpawner::~ChickenSpawner()
{}

void ChickenSpawner::Update(float delta_time)
{
    timer_ -= delta_time;
    if (timer_ <= 0.0f)
    {
        timer_ = rand() % 5 + 1;
        scene_->AddGameObject(new Chicken(sf::Vector2f(1920, -100), chickenID_, scene_));
        chickenID_++;
    }
}

void ChickenSpawner::Draw()
{}