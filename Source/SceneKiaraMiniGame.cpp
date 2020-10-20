#include "../Header/SceneKiaraMiniGame.h"
#include "../Header/LP.h"
#include "../Header/ID.h"
#include "../Header/Kiara.h"
#include "../Header/ChickenSpawner.h"
#include "../Header/InaDoor.h"

SceneKiaraMiniGame::SceneKiaraMiniGame(Game* game) : game_{game}
{}

SceneKiaraMiniGame::~SceneKiaraMiniGame()
{}

void SceneKiaraMiniGame::Init()
{
    game_->GetCamera()->SetCameraViewSize(1920, 1080);
    game_->GetCamera()->SetTarget(sf::Vector2f(1920/2, 1080/2));

    background_ = LP::SetSprite(background_image);
    gom_.Add(new Kiara(sf::Vector2f(0.0f, 30.0f), this));
    gom_.Add(new ChickenSpawner(this));
    game_->PlayMusic(kiara_theme, true);

    AddGameObject(new InaDoor(sf::Vector2f(game_->GetCamera()->GetCameraLeftEdge(), game_->GetCamera()->GetCameraTopEdge()), 
                              sf::Vector2f(game_->GetCamera()->GetCameraLeftEdge() - 1920/2, game_->GetCamera()->GetCameraTopEdge()), this));
    AddGameObject(new InaDoor(sf::Vector2f(game_->GetCamera()->GetCameraCenter().x, game_->GetCamera()->GetCameraTopEdge()), 
                              sf::Vector2f(game_->GetCamera()->GetCameraRightEdge(), game_->GetCamera()->GetCameraTopEdge()), this));
}

void SceneKiaraMiniGame::Update(float delta_time)
{
    gom_.Update(delta_time);
    gom_.Collision();
    gom_.Remove();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        ChangeScene("Title");
    }
}

void SceneKiaraMiniGame::Draw()
{
    LP::DrawSprite(background_);
    gom_.Draw();
}

void SceneKiaraMiniGame::AddGameObject(GameObject* gameObject)
{
    gom_.Add(gameObject);
}

void SceneKiaraMiniGame::ChangeScene(const std::string& sceneName)
{
    game_->ChangeScene(sceneName);
}

void SceneKiaraMiniGame::End()
{
    LP::DeleteSprite(background_);
    gom_.Clear();
}