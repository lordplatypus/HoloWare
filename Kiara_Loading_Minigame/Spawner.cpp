#include "Spawner.h"
#include "Chicken.h"
#include "Rock.h"

Spawner::Spawner(int difficulty, Scene* scene)
{
    scene_ = scene;
    tag_ = "Spawner";
    name_ = "ChickenSpawner";
    difficulty_ = difficulty;
    odds_ = difficulty_;
}

Spawner::~Spawner()
{}

void Spawner::Update(float delta_time)
{
    timer_ -= delta_time;
    if (timer_ <= 0.0f)
    {
        timer_ = (float)(rand() % 5) / 10.0f + 0.5f;
        ChooseObjectToSpawn();
    }
}

void Spawner::ChooseObjectToSpawn()
{
    int randObject = rand() % 10;
    if (randObject < 5 + odds_)
    {
        scene_->AddGameObject(new Rock(sf::Vector2f(480, -10), scene_));
        odds_--;
    }
    else
    {
        scene_->AddGameObject(new Chicken(sf::Vector2f(480, -10), scene_));
        odds_ = difficulty_;
    }
    scene_->SortGameObjects();
}