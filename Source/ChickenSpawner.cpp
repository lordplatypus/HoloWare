#include "../Header/ChickenSpawner.h"
#include "../Header/Chicken.h"

ChickenSpawner::ChickenSpawner(Scene* scene)
{
    scene_ = scene;
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
        scene_->AddGameObject(new Chicken(sf::Vector2f(1920, -100), scene_));
        chickenID_++;
    }
}

void ChickenSpawner::Draw()
{}