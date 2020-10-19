#include "../Header/SceneGame.h"
#include "../Header/LP.h"
#include "../Header/ID.h"
#include "../Header/Kiara.h"
#include "../Header/ChickenSpawner.h"

SceneGame::SceneGame(Game* game) : game_{game}
{}

SceneGame::~SceneGame()
{}

void SceneGame::Init()
{
    background_ = LP::SetSprite(background_image);
    gom_.Add(new Kiara(sf::Vector2f(0.0f, 30.0f), this));
    gom_.Add(new ChickenSpawner(this));
    game_->PlayMusic(kiara_theme, true);
}

void SceneGame::Update(float delta_time)
{
    gom_.Update(delta_time);
    gom_.Collision();
    gom_.Remove();
}

void SceneGame::Draw()
{
    LP::DrawSprite(background_);
    gom_.Draw();
}

void SceneGame::AddGameObject(GameObject* gameObject)
{
    gom_.Add(gameObject);
}

void SceneGame::ChangeScene(const std::string& sceneName)
{
    game_->ChangeScene(sceneName);
}

void SceneGame::End()
{
    LP::DeleteSprite(background_);
    gom_.Clear();
}