#include "../Header/KiaraChickenScene.h"
#include "../Header/LP.h"
#include "../Header/ID.h"
#include "../Header/KiaraChickenKiara.h"
#include "../Header/KiaraChickenSpawner.h"
#include "../Header/InaTransitionDoor.h"

KiaraChickenScene::KiaraChickenScene(Game* game) : game_{game}
{}

KiaraChickenScene::~KiaraChickenScene()
{}

void KiaraChickenScene::Init()
{
    game_->GetCamera()->SetCameraViewSize(1920, 1080);
    game_->GetCamera()->SetTarget(sf::Vector2f(1920/2, 1080/2));

    background_ = LP::SetSprite(kiara_chicken_background_image);
    gom_.Add(new KiaraChickenKiara(sf::Vector2f(0.0f, 30.0f), this));
    gom_.Add(new KiaraChickenSpawner(this));
    game_->PlayMusic(kiara_theme, true);

    AddGameObject(new InaTransitionDoor(sf::Vector2f(game_->GetCamera()->GetCameraLeftEdge(), game_->GetCamera()->GetCameraTopEdge()), 
                              sf::Vector2f(game_->GetCamera()->GetCameraLeftEdge() - 1920/2, game_->GetCamera()->GetCameraTopEdge()), this, 4.0f));
    AddGameObject(new InaTransitionDoor(sf::Vector2f(game_->GetCamera()->GetCameraCenter().x, game_->GetCamera()->GetCameraTopEdge()), 
                              sf::Vector2f(game_->GetCamera()->GetCameraRightEdge(), game_->GetCamera()->GetCameraTopEdge()), this, 4.0f));
}

void KiaraChickenScene::Update(float delta_time)
{
    gom_.Update(delta_time);
    gom_.Collision();
    gom_.Remove();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        ChangeScene("InaTransition");
    }
}

void KiaraChickenScene::Draw()
{
    LP::DrawSprite(background_);
    gom_.Draw();
}

void KiaraChickenScene::AddGameObject(GameObject* gameObject)
{
    gom_.Add(gameObject);
}

void KiaraChickenScene::OnWin()
{
    game_->GetMiniGameManager()->SetWin(true);
}

void KiaraChickenScene::OnLoss()
{
    game_->GetMiniGameManager()->SetWin(false);
    game_->GetMiniGameManager()->DecrementHP();
}

void KiaraChickenScene::ChangeScene(const std::string& sceneName)
{
    game_->ChangeScene(sceneName);
}

void KiaraChickenScene::End()
{
    LP::DeleteSprite(background_);
    gom_.Clear();
}