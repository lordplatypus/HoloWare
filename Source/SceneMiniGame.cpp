#include "../Header/SceneMiniGame.h"
#include "../Header/LP.h"
#include "../Header/ID.h"
#include "../Header/InaTransitionDoor.h"
#include "../Header/InaTransitionHP.h"
#include "../Header/InaTransitionLoading.h"
#include "../Header/InaTransitionTimer.h"

SceneMiniGame::SceneMiniGame(Game* game) : game_{game}
{}

SceneMiniGame::~SceneMiniGame()
{}

void SceneMiniGame::Init()
{//Occurs everytime the scene is loaded
    state_ = First;

    if (game_->GetWin())
    {//win

    }
    else
    {//lose
        hp_--;
    }
    game_->SetWin(false); //reset win for next game

    game_->GetCamera()->SetCameraViewSize(480, 270);
    game_->GetCamera()->SetTarget(sf::Vector2f(480/2, 270/2));

    background_ = LP::SetSprite(ina_transition_background_image, sf::Vector2f(0.0f, 0.0f));

    AddGameObject(new InaTransitionLoading(sf::Vector2f(game_->GetCamera()->GetCameraCenter().x - 160, game_->GetCamera()->GetCameraTopEdge() + 64), this));

    timer_ = 5.0f;
    timerText_ = LP::SetText(std::to_string(timer_), sf::Vector2f(game_->GetCamera()->GetCameraCenter().x, game_->GetCamera()->GetCameraBottomEdge() - 64), 32);
    LP::SetTextOriginCenter(timerText_);

    for (int i = 0; i < hp_; i++) 
        AddGameObject(new InaTransitionHP(sf::Vector2f((game_->GetCamera()->GetCameraCenter().x - ((64 * hp_) / 2)) + 32 + (i * 64), game_->GetCamera()->GetCameraCenter().y), this));

    AddGameObject(new InaTransitionTimer(sf::Vector2f(game_->GetCamera()->GetCameraLeftEdge(), game_->GetCamera()->GetCameraBottomEdge() - 64), 3, 1.0f, this));

    AddGameObject(new InaTransitionDoor(sf::Vector2f(game_->GetCamera()->GetCameraLeftEdge(), game_->GetCamera()->GetCameraTopEdge()), 
                              sf::Vector2f(game_->GetCamera()->GetCameraLeftEdge() - 240, game_->GetCamera()->GetCameraTopEdge()), this));
    AddGameObject(new InaTransitionDoor(sf::Vector2f(game_->GetCamera()->GetCameraCenter().x, game_->GetCamera()->GetCameraTopEdge()), 
                              sf::Vector2f(game_->GetCamera()->GetCameraRightEdge(), game_->GetCamera()->GetCameraTopEdge()), this));
}

void SceneMiniGame::Reset()
{//Occurs only when called (intended to be called if game is lost/quit)
    hp_ = 4;
}

void SceneMiniGame::Update(float delta_time)
{
    gom_.Update(delta_time);
    gom_.Collision();
    gom_.Remove();

    timer_ -= delta_time;
    if (timer_ <= 0.0f)
    {
        RandomMiniGame();
    }
    else if (state_ == First && timer_ <= 1.0f)
    {
        state_ = Second;
        AddGameObject(new InaTransitionDoor(sf::Vector2f(game_->GetCamera()->GetCameraLeftEdge() - 240, game_->GetCamera()->GetCameraTopEdge()), 
                                  sf::Vector2f(game_->GetCamera()->GetCameraLeftEdge(), game_->GetCamera()->GetCameraTopEdge()), this));
        AddGameObject(new InaTransitionDoor(sf::Vector2f(game_->GetCamera()->GetCameraRightEdge(), game_->GetCamera()->GetCameraTopEdge()), 
                                  sf::Vector2f(game_->GetCamera()->GetCameraCenter().x, game_->GetCamera()->GetCameraTopEdge()), this));
    }
    LP::SetTextString(timerText_, std::to_string(timer_));
}

void SceneMiniGame::Draw()
{
    LP::DrawSprite(background_);
    LP::DrawText(timerText_);
    gom_.Draw();
}

void SceneMiniGame::AddGameObject(GameObject* gameObject)
{
    gom_.Add(gameObject);
}

void SceneMiniGame::OnWin()
{}

void SceneMiniGame::ChangeScene(const std::string& sceneName)
{
    game_->ChangeScene(sceneName);
}

void SceneMiniGame::End()
{
    gom_.Clear();
    LP::DeleteText(timerText_);
    LP::DeleteSprite(background_);
}

void SceneMiniGame::RandomMiniGame()
{
    int randMiniGame = rand() % game_->GetMiniGameCount();
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