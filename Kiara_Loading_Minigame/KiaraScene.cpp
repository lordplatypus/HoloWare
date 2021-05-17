#include "KiaraScene.h"
#include "../Lib/LP.h"
#include "../Lib/MP.h"
#include "../Lib/ID.h"
#include "../Lib/IP.h"
#include "Background.h"
#include "Kiara.h"
#include "Spawner.h"
#include "../Ina_Transition/InaTransitionDoorOpen.h"
#include "../Ina_Transition/InaTransitionTimer.h"

KiaraScene::KiaraScene(Game* game) : game_{game}
{}

KiaraScene::~KiaraScene()
{}

void KiaraScene::Init()
{
    // FindView("Main")->setSize(sf::Vector2f(1920.0f, 1080.0f));
    // FindView("Main")->setCenter(sf::Vector2f(1920.0f/2, 1080.0f/2));
    FindView("Main")->setSize(sf::Vector2f(480, 270));
    FindView("Main")->setCenter(sf::Vector2f(480/2, 270/2));

    for (int i = 0; i < 15; i++) 
    {
        people_.push_back(new BackgroundPeople(sf::Vector2f(32 * i, 145), this));
        gom_.Add(people_[i]);
    }
    gom_.Add(new Background(this));
    gom_.Add(new Kiara(sf::Vector2f(270.0f / 2, 200.0f), game_->GetMiniGameManager().GetDifficulty(), &pm_, this));
    gom_.Add(new Spawner(game_->GetMiniGameManager().GetDifficulty(), this));
    for (int i = 0; i < 4; i++) 
    {
        register_.push_back(new Register(sf::Vector2f((480.0f / 9.0f) + (480.0f / 9.0f * 2) * i, 155), &pm_, this));
        gom_.Add(register_[i]);
    }

    MP::PlayMusic(kiara_theme);

    textAlpha_ = 255;
    text_ = LP::SetText("Collect at least " + std::to_string(game_->GetMiniGameManager().GetDifficulty() + 1) + " chicken leg(s)!", sf::Vector2f(FindView("Main")->getCenter()), 64);
    LP::SetTextOriginCenter(&text_);
    text_.setScale(0.2f, 0.2f);
    text_.setFillColor(sf::Color::White);

    float sec = 7.0f - game_->GetMiniGameManager().GetTimerModifier();
    AddGameObject(new InaTransitionTimer(sf::Vector2f(0.0f, FindView("Transition")->getSize().y - 32), sec, this));

    AddGameObject(new InaTransitionDoorOpen(this));

    SortGameObjects();
}

void KiaraScene::Update(float delta_time)
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
            text_.setFillColor(sf::Color(255, 255, 255, textAlpha_));
            textTimer_ = 0.1f;
        }
    }

    if (changeScene_)
    {
        changeScene_ = false;
        game_->ChangeScene("InaTransition");
    }

    if (IP::PressX())
    {
        game_->ChangeScene("InaTransition");
    }
}

void KiaraScene::Draw(sf::RenderWindow& render_window) const
{
    gom_.Draw(render_window);
    render_window.draw(text_);
}

void KiaraScene::AddGameObject(GameObject* gameObject)
{
    gom_.Add(gameObject);
}

GameObject* KiaraScene::FindGameObject(const std::string& string, const bool byName, const bool byTag, const bool byID)
{//if byTag and byID are both left to default (false), search by name
    return gom_.Find(string, byName, byTag, byID); //returns a GameObject, returns a nullptr if the GameObject is not found
}

void KiaraScene::SortGameObjects()
{
    gom_.SortByLayers();
}

sf::View* KiaraScene::FindView(const std::string& viewName)
{
    return game_->GetCamera()->GetView(viewName);
}

void KiaraScene::SetOutcome(const bool outcome)
{
    game_->GetMiniGameManager().SetOutcome(outcome);
    for (int i = 0; i < 4; i++) register_[i]->SetOutcome(outcome);
    for (int i = 0; i < 15; i++) people_[i]->SetOutcome(outcome);
}

void KiaraScene::ChangeScene(const std::string& sceneName)
{
    changeScene_ = true;
}

void KiaraScene::End()
{
    gom_.Clear();
    MP::StopMusic(kiara_theme);
    people_.clear();
    register_.clear();
}