#include "../Header/InaTransitionScene.h"
#include "../Header/LP.h"
#include "../Header/ID.h"
#include "../Header/InaTransitionDoor.h"
#include "../Header/InaTransitionDoorOpen.h"
#include "../Header/InaTransitionHP.h"
#include "../Header/InaTransitionLoading.h"
#include "../Header/InaTransitionTimer.h"

InaTransitionScene::InaTransitionScene(Game* game) : game_{game}
{}

InaTransitionScene::~InaTransitionScene()
{}

void InaTransitionScene::Init()
{//Occurs everytime the scene is loaded
    game_->GetMiniGameManager()->IncrementPlayCount();
    if (game_->GetMiniGameManager()->GetPlayCount() % 10 == 0 && game_->GetMiniGameManager()->GetPlayCount() != 0)
    {
        state_ = DifficultyUp;
        if (game_->GetMiniGameManager()->GetDifficulty() == hard_difficulty) return;
        else game_->GetMiniGameManager()->SetDifficulty(game_->GetMiniGameManager()->GetDifficulty() + 1);
    }
    else if (game_->GetMiniGameManager()->GetWin())
    {//win
        state_ = WinState;
        game_->GetMiniGameManager()->SetTimerModifier(game_->GetMiniGameManager()->GetTimerModifier() + 0.1f);
    }
    else
    {//lose
        state_ = LossState;
    }
    game_->GetMiniGameManager()->SetWin(false); //reset win for next game

    game_->GetCamera()->SetCameraViewSize(480, 270);
    game_->GetCamera()->SetTarget(sf::Vector2f(480/2, 270/2));

    background_ = LP::SetSprite(ina_transition_background_image, sf::Vector2f(0.0f, 0.0f));

    AddGameObject(new InaTransitionLoading(sf::Vector2f(game_->GetCamera()->GetCameraCenter().x - 160, game_->GetCamera()->GetCameraTopEdge() + 64), this));

    timer_ = 5.0f - game_->GetMiniGameManager()->GetTimerModifier();
    timerText_ = LP::SetText(std::to_string(timer_) + " " + std::to_string(game_->GetMiniGameManager()->GetTimerModifier()), sf::Vector2f(game_->GetCamera()->GetCameraCenter().x, game_->GetCamera()->GetCameraBottomEdge() - 64), 16);
    LP::SetTextOriginCenter(timerText_);
    miniGameCountText_ = LP::SetText(std::to_string(game_->GetMiniGameManager()->GetPlayCount()), sf::Vector2f(game_->GetCamera()->GetCameraLeftEdge(), game_->GetCamera()->GetCameraTopEdge()), 32);

    int hp = game_->GetMiniGameManager()->GetHP();
    for (int i = 0; i < hp; i++) 
        AddGameObject(new InaTransitionHP(sf::Vector2f((game_->GetCamera()->GetCameraCenter().x - ((64 * hp) / 2)) + 32 + (i * 64), game_->GetCamera()->GetCameraCenter().y), this));

    AddGameObject(new InaTransitionTimer(sf::Vector2f(game_->GetCamera()->GetCameraLeftEdge(), game_->GetCamera()->GetCameraBottomEdge() - 64), 
                                         2.0f - game_->GetMiniGameManager()->GetTimerModifier(), game_->GetCamera(), this));

    AddGameObject(new InaTransitionDoorOpen(game_->GetCamera(), this));
}

void InaTransitionScene::Reset()
{}

void InaTransitionScene::Update(float delta_time)
{
    gom_.Update(delta_time);
    gom_.Collision();
    gom_.Remove();

    if (changeScene_)
    {
        changeScene_ = false;
        RandomMiniGame();
    }

    timer_ -= delta_time;
    LP::SetTextString(timerText_, std::to_string(timer_) + " " + std::to_string(game_->GetMiniGameManager()->GetTimerModifier()));
}

void InaTransitionScene::Draw()
{
    LP::DrawSprite(background_);
    LP::DrawText(timerText_);
    LP::DrawText(miniGameCountText_);
    gom_.Draw();
}

void InaTransitionScene::AddGameObject(GameObject* gameObject)
{
    gom_.Add(gameObject);
}

void InaTransitionScene::OnWin()
{}

void InaTransitionScene::OnLoss()
{}

void InaTransitionScene::ChangeScene()
{
    changeScene_ = true;
}

void InaTransitionScene::End()
{
    gom_.Clear();
    LP::DeleteText(timerText_);
    LP::DeleteText(miniGameCountText_);
    LP::DeleteSprite(background_);
}

void InaTransitionScene::RandomMiniGame()
{
    //int randMiniGame = rand() % 2;
    int randMiniGame = 1;
    switch (randMiniGame)
    {
    case 0:
        game_->ChangeScene("KiaraChicken");
        break;

    case 1:
        game_->ChangeScene("KoroneYubi");
        break;
    
    default:
        break;
    }
}