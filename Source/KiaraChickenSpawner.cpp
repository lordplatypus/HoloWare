#include "../Header/KiaraChickenSpawner.h"
#include "../Header/KiaraChickenChicken.h"

KiaraChickenSpawner::KiaraChickenSpawner(Scene* scene)
{
    scene_ = scene;
    tag_ = "Spawner";
    name_ = "ChickenSpawner";
}

KiaraChickenSpawner::~KiaraChickenSpawner()
{}

void KiaraChickenSpawner::Update(float delta_time)
{
    timer_ -= delta_time;
    if (timer_ <= 0.0f)
    {
        timer_ = rand() % 5 + 1;
        scene_->AddGameObject(new KiaraChickenChicken(sf::Vector2f(1920, -100), scene_));
        chickenID_++;
    }
}

void KiaraChickenSpawner::Draw()
{}