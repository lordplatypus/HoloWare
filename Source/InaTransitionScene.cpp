#include "../Header/InaTransitionScene.h"
#include "../Header/LP.h"
#include "../Header/ID.h"
#include "../Header/InaTransitionDoor.h"
#include "../Header/InaTransitionHP.h"
#include "../Header/InaTransitionLoading.h"
#include "../Header/InaTransitionTimer.h"

InaTransitionScene::InaTransitionScene(Game* game) : game_{game}
{}

InaTransitionScene::~InaTransitionScene()
{}

void InaTransitionScene::Init()
{//Occurs everytime the scene is loaded
    if (game_->GetMiniGameManager()->GetPlayCount() % 10 == 0)
    {
        state_ = DifficultyUp;
        if (game_->GetMiniGameManager()->GetDifficulty() == hard_difficulty) return;
        else game_->GetMiniGameManager()->SetDifficulty(game_->GetMiniGameManager()->GetDifficulty() + 1);
    }
    else if (game_->GetMiniGameManager()->GetWin())
    {//win
        state_ = WinState;
    }
    else
    {//lose
        state_ = LossState;
    }
    game_->GetMiniGameManager()->IncrementPlayCount();
    game_->GetMiniGameManager()->SetWin(false); //reset win for next game

    game_->GetCamera()->SetCameraViewSize(480, 270);
    game_->GetCamera()->SetTarget(sf::Vector2f(480/2, 270/2));

    background_ = LP::SetSprite(ina_transition_background_image, sf::Vector2f(0.0f, 0.0f));

    AddGameObject(new InaTransitionLoading(sf::Vector2f(game_->GetCamera()->GetCameraCenter().x - 160, game_->GetCamera()->GetCameraTopEdge() + 64), this));

    timer_ = 5.0f;
    timerText_ = LP::SetText(std::to_string(timer_), sf::Vector2f(game_->GetCamera()->GetCameraCenter().x, game_->GetCamera()->GetCameraBottomEdge() - 64), 32);
    LP::SetTextOriginCenter(timerText_);

    int hp = game_->GetMiniGameManager()->GetHP();
    for (int i = 0; i < hp; i++) 
        AddGameObject(new InaTransitionHP(sf::Vector2f((game_->GetCamera()->GetCameraCenter().x - ((64 * hp) / 2)) + 32 + (i * 64), game_->GetCamera()->GetCameraCenter().y), this));

    AddGameObject(new InaTransitionTimer(sf::Vector2f(game_->GetCamera()->GetCameraLeftEdge(), game_->GetCamera()->GetCameraBottomEdge() - 64), 3, 1.0f, this));

    AddGameObject(new InaTransitionDoor(sf::Vector2f(game_->GetCamera()->GetCameraLeftEdge(), game_->GetCamera()->GetCameraTopEdge()), 
                              sf::Vector2f(game_->GetCamera()->GetCameraLeftEdge() - 240, game_->GetCamera()->GetCameraTopEdge()), this));
    AddGameObject(new InaTransitionDoor(sf::Vector2f(game_->GetCamera()->GetCameraCenter().x, game_->GetCamera()->GetCameraTopEdge()), 
                              sf::Vector2f(game_->GetCamera()->GetCameraRightEdge(), game_->GetCamera()->GetCameraTopEdge()), this));
}

void InaTransitionScene::Reset()
{//Occurs only when called (intended to be called if game is lost/quit)
}

void InaTransitionScene::Update(float delta_time)
{
    gom_.Update(delta_time);
    gom_.Collision();
    gom_.Remove();

    timer_ -= delta_time;
    if (timer_ <= 0.0f)
    {
        RandomMiniGame();
    }
    else if (state_ != CloseDoor && timer_ <= 1.0f)
    {
        state_ = CloseDoor;
        AddGameObject(new InaTransitionDoor(sf::Vector2f(game_->GetCamera()->GetCameraLeftEdge() - 240, game_->GetCamera()->GetCameraTopEdge()), 
                                  sf::Vector2f(game_->GetCamera()->GetCameraLeftEdge(), game_->GetCamera()->GetCameraTopEdge()), this));
        AddGameObject(new InaTransitionDoor(sf::Vector2f(game_->GetCamera()->GetCameraRightEdge(), game_->GetCamera()->GetCameraTopEdge()), 
                                  sf::Vector2f(game_->GetCamera()->GetCameraCenter().x, game_->GetCamera()->GetCameraTopEdge()), this));
    }
    LP::SetTextString(timerText_, std::to_string(timer_));
}

void InaTransitionScene::Draw()
{
    LP::DrawSprite(background_);
    LP::DrawText(timerText_);
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

void InaTransitionScene::ChangeScene(const std::string& sceneName)
{
    game_->ChangeScene(sceneName);
}

void InaTransitionScene::End()
{
    gom_.Clear();
    LP::DeleteText(timerText_);
    LP::DeleteSprite(background_);
}

void InaTransitionScene::RandomMiniGame()
{
    int randMiniGame = rand() % 2;
    switch (randMiniGame)
    {
    case 0:
        ChangeScene("KiaraChicken");
        break;

    case 1:
        ChangeScene("KoroneYubi");
        break;
    
    default:
        break;
    }
}