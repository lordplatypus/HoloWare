#include "../Header/KiaraChickenScene.h"
#include "../Header/LP.h"
#include "../Header/MP.h"
#include "../Header/ID.h"
#include "../Header/KiaraChickenKiara.h"
#include "../Header/KiaraChickenSpawner.h"
#include "../Header/InaTransitionDoorOpen.h"
#include "../Header/InaTransitionTimer.h"

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
    gom_.Add(new KiaraChickenSpawner(game_->GetMiniGameManager()->GetDifficulty(), this));
    MP::PlayMusic(kiara_theme);

    textAlpha_ = 255;
    text_ = LP::SetText("Collect at least 1 chicken leg!", sf::Vector2f(game_->GetCamera()->GetCameraCenter()), 128);
    LP::SetTextOriginCenter(text_);
    LP::SetTextScale(text_, .2f, .2f);

    float sec = 7.0f - game_->GetMiniGameManager()->GetTimerModifier();
    AddGameObject(new InaTransitionTimer(sf::Vector2f(game_->GetCamera()->GetCameraLeftEdge(), game_->GetCamera()->GetCameraBottomEdge() - 64 * 4), sec, game_->GetCamera(), this, 4.0f));

    AddGameObject(new InaTransitionDoorOpen(game_->GetCamera(), this, 4.0f));
}

void KiaraChickenScene::Update(float delta_time)
{
    gom_.Update(delta_time);
    gom_.Collision();
    gom_.Remove();

    if (textAlpha_ > 0) 
    {
        textTimer_ -= delta_time;
        if (textTimer_ < 0.0f)
        {
            textAlpha_ -= 10;
            if (textAlpha_ < 0) textAlpha_ = 0;
            LP::SetTextColor(text_, 0, 0, 0, textAlpha_);
            textTimer_ = 0.1f;
        }
    }

    if (changeScene_)
    {
        changeScene_ = false;
        OnLoss();
        game_->ChangeScene("InaTransition");
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        OnLoss();
        game_->ChangeScene("InaTransition");
    }
}

void KiaraChickenScene::Draw()
{
    LP::DrawSprite(background_);
    gom_.Draw();
    LP::DrawText(text_);
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
    if (game_->GetMiniGameManager()->GetWin()) return;
    game_->GetMiniGameManager()->SetWin(false);
    game_->GetMiniGameManager()->DecrementHP();
}

void KiaraChickenScene::ChangeScene()
{
    changeScene_ = true;
}

void KiaraChickenScene::End()
{
    LP::DeleteSprite(background_);
    gom_.Clear();
    MP::StopMusic(kiara_theme);
    LP::DeleteText(text_);
}