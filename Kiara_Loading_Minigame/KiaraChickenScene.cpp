#include "KiaraChickenScene.h"
#include "../Lib/LP.h"
#include "../Lib/MP.h"
#include "../Lib/ID.h"
#include "KiaraChickenKiara.h"
#include "KiaraChickenSpawner.h"
#include "../Ina_Transition/InaTransitionDoorOpen.h"
#include "../Ina_Transition/InaTransitionTimer.h"

KiaraChickenScene::KiaraChickenScene(Game* game) : game_{game}
{}

KiaraChickenScene::~KiaraChickenScene()
{}

void KiaraChickenScene::Init()
{
    FindView("Main")->setSize(sf::Vector2f(1920.0f, 1080.0f));
    FindView("Main")->setCenter(sf::Vector2f(1920.0f/2, 1080.0f/2));

    background_ = LP::SetSprite(kiara_chicken_background_image);
    gom_.Add(new KiaraChickenKiara(sf::Vector2f(0.0f, 30.0f), this));
    gom_.Add(new KiaraChickenSpawner(game_->GetMiniGameManager().GetDifficulty(), this));
    MP::PlayMusic(kiara_theme);

    textAlpha_ = 255;
    text_ = LP::SetText("Collect at least 1 chicken leg!", sf::Vector2f(FindView("Main")->getCenter()), 128);
    LP::SetTextOriginCenter(&text_);
    text_.setScale(0.2f, 0.2f);

    float sec = 7.0f - game_->GetMiniGameManager().GetTimerModifier();
    AddGameObject(new InaTransitionTimer(sf::Vector2f(0.0f, FindView("Transition")->getSize().y - 32), sec, this));

    AddGameObject(new InaTransitionDoorOpen(this));
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
            text_.setFillColor(sf::Color(0, 0, 0, textAlpha_));
            textTimer_ = 0.1f;
        }
    }

    if (changeScene_)
    {
        changeScene_ = false;
        game_->ChangeScene("InaTransition");
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        game_->ChangeScene("InaTransition");
    }
}

void KiaraChickenScene::Draw(sf::RenderWindow& render_window) const
{
    render_window.draw(background_);
    gom_.Draw(render_window);
    render_window.draw(text_);
}

void KiaraChickenScene::AddGameObject(GameObject* gameObject)
{
    gom_.Add(gameObject);
}

GameObject* KiaraChickenScene::FindGameObject(const std::string& string, const bool byName, const bool byTag, const bool byID)
{//if byTag and byID are both left to default (false), search by name
    return gom_.Find(string, byName, byTag, byID); //returns a GameObject, returns a nullptr if the GameObject is not found
}

void KiaraChickenScene::SortGameObjects()
{
    gom_.SortByLayers();
}

sf::View* KiaraChickenScene::FindView(const std::string& viewName)
{
    return game_->GetCamera()->GetView(viewName);
}

void KiaraChickenScene::SetOutcome(const bool outcome)
{
    game_->GetMiniGameManager().SetWin(outcome);
}

void KiaraChickenScene::ChangeScene(const std::string& sceneName)
{
    changeScene_ = true;
}

// void KiaraChickenScene::OnWin()
// {
//     game_->GetMiniGameManager()->SetWin(true);
// }

// void KiaraChickenScene::OnLoss()
// {
//     if (game_->GetMiniGameManager()->GetWin()) return;
//     game_->GetMiniGameManager()->SetWin(false);
//     game_->GetMiniGameManager()->DecrementHP();
// }

// void KiaraChickenScene::ChangeScene()
// {
//     changeScene_ = true;
// }

void KiaraChickenScene::End()
{
    gom_.Clear();
    MP::StopMusic(kiara_theme);
}