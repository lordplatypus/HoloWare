#include "../Header/MiniGame.h"

MiniGame::MiniGame()
{}

MiniGame::~MiniGame()
{}

void MiniGame::Update(float delta_time)
{}

void MiniGame::Draw()
{}

void MiniGame::AddGameObject(GameObject* gameObject)
{
    gom_.Add(gameObject);
}

GameObject* MiniGame::FindGameObjectByTag(const std::string& tag)
{
    return gom_.Find(tag);
}

GameObject* MiniGame::FindGameObjectByName(const std::string& name)
{
    return gom_.Find(name);
}

bool MiniGame::IsClear() const
{
    return clear_;
}