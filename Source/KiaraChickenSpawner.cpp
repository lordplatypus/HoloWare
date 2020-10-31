#include "../Header/KiaraChickenSpawner.h"
#include "../Header/KiaraChickenChicken.h"
#include "../Header/KiaraChickenRock.h"

KiaraChickenSpawner::KiaraChickenSpawner(int difficulty, Scene* scene)
{
    scene_ = scene;
    tag_ = "Spawner";
    name_ = "ChickenSpawner";
    difficulty_ = difficulty;
    odds_ = difficulty_;
}

KiaraChickenSpawner::~KiaraChickenSpawner()
{}

void KiaraChickenSpawner::Update(float delta_time)
{
    timer_ -= delta_time;
    if (timer_ <= 0.0f)
    {
        timer_ = (float)(rand() % 5) / 10.0f + 0.5f;
        ChooseObjectToSpawn();
    }
}

void KiaraChickenSpawner::ChooseObjectToSpawn()
{
    int randObject = rand() % 10;
    if (randObject < 5 + odds_)
    {
        scene_->AddGameObject(new KiaraChickenRock(sf::Vector2f(1920, -100), scene_));
        odds_--;
    }
    else
    {
        scene_->AddGameObject(new KiaraChickenChicken(sf::Vector2f(1920, -100), scene_));
        odds_ = difficulty_;
    }
}