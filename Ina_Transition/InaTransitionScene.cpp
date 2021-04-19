#include "InaTransitionScene.h"
#include "../Lib/LP.h"
#include "../Lib/MP.h"
#include "../Lib/ID.h"
#include "InaTransitionDoor.h"
#include "InaTransitionDoorOpen.h"
#include "InaTransitionHP.h"
#include "InaTransitionLoading.h"
#include "InaTransitionTimer.h"

InaTransitionScene::InaTransitionScene(Game* game) : game_{game}
{}

InaTransitionScene::~InaTransitionScene()
{}

void InaTransitionScene::Init()
{//Occurs everytime the scene is loaded
    game_->GetMiniGameManager().IncrementPlayCount();
    if (game_->GetMiniGameManager().GetPlayCount() % 10 == 0 && game_->GetMiniGameManager().GetPlayCount() != 0)
    {
        state_ = DifficultyUp;
        if (game_->GetMiniGameManager().GetDifficulty() != hard_difficulty) game_->GetMiniGameManager().SetDifficulty(game_->GetMiniGameManager().GetDifficulty() + 1);
    }
    else if (game_->GetMiniGameManager().GetWin())
    {//win
        state_ = WinState;
        game_->GetMiniGameManager().SetTimerModifier(game_->GetMiniGameManager().GetTimerModifier() + 0.1f);
        MP::SetSoundSpeed(win_se, 1.0f + game_->GetMiniGameManager().GetTimerModifier() / 10.0f);
        MP::PlaySound(win_se);
    }
    else
    {//lose
        state_ = LossState;
        MP::PlaySound(lose_se);
    }
    game_->GetMiniGameManager().SetWin(false); //reset win for next game

    background_ = LP::SetSprite(ina_transition_background_image, sf::Vector2f(0.0f, 0.0f));

    AddGameObject(new InaTransitionLoading(sf::Vector2f(FindView("Transition")->getCenter().x - 160, 64), this));

    timer_ = 5.0f - game_->GetMiniGameManager().GetTimerModifier();
    timerText_ = LP::SetText(std::to_string(timer_) + " " + std::to_string(game_->GetMiniGameManager().GetTimerModifier()), sf::Vector2f(FindView("Transition")->getCenter().x, FindView("Transition")->getSize().y - 64), 16);
    LP::SetTextOriginCenter(&timerText_);
    miniGameCountText_ = LP::SetText(std::to_string(game_->GetMiniGameManager().GetPlayCount()), sf::Vector2f(0.0f, 0.0f), 32);

    int hp = game_->GetMiniGameManager().GetHP();
    for (int i = 0; i < hp; i++) 
        AddGameObject(new InaTransitionHP(sf::Vector2f((FindView("Transition")->getCenter().x - ((64 * hp) / 2)) + 32 + (i * 64), FindView("Transition")->getCenter().y), this));

    AddGameObject(new InaTransitionTimer(sf::Vector2f(0.0f, FindView("Transition")->getSize().y - 32), 
                                         2.0f - game_->GetMiniGameManager().GetTimerModifier(), this));

    AddGameObject(new InaTransitionDoorOpen(this));
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
    timerText_.setString(std::to_string(timer_) + " " + std::to_string(game_->GetMiniGameManager().GetTimerModifier()));
}

void InaTransitionScene::Draw(sf::RenderWindow& render_window) const
{
    render_window.draw(background_);
    render_window.draw(timerText_);
    render_window.draw(miniGameCountText_);
    gom_.Draw(render_window);
}

void InaTransitionScene::AddGameObject(GameObject* gameObject)
{
    gom_.Add(gameObject);
}

GameObject* InaTransitionScene::FindGameObject(const std::string& string, const bool byName, const bool byTag, const bool byID)
{//if byTag and byID are both left to default (false), search by name
    return gom_.Find(string, byName, byTag, byID); //returns a GameObject, returns a nullptr if the GameObject is not found
}

void InaTransitionScene::SortGameObjects()
{
    gom_.SortByLayers();
}

sf::View* InaTransitionScene::FindView(const std::string& viewName)
{
    return game_->GetCamera()->GetView(viewName);
}

void InaTransitionScene::SetOutcome(const bool outcome)
{
    game_->GetMiniGameManager().SetWin(outcome);
}

void InaTransitionScene::ChangeScene(const std::string& sceneName)
{
    changeScene_ = true;
}

void InaTransitionScene::End()
{
    gom_.Clear();
}

void InaTransitionScene::RandomMiniGame()
{
    int randMiniGame = rand() % 2;
    //int randMiniGame = 1;
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