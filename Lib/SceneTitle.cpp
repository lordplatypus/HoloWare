#include "SceneTitle.h"
#include "LP.h"
#include "ID.h"

SceneTitle::SceneTitle(Game* game) : game_{game}
{}

SceneTitle::~SceneTitle()
{}

void SceneTitle::Init()
{
    game_->GetMiniGameManager().Reset();

    titleText_ = LP::SetText("HoloWare", FindView("Main")->getCenter(), 128);
    LP::SetTextOriginCenter(&titleText_);
}

void SceneTitle::Update(float delta_time)
{
    gom_.Update(delta_time);
    gom_.Collision();
    gom_.Remove();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        ChangeScene("InaTransition");
    }
}

void SceneTitle::Draw(sf::RenderWindow& render_window) const
{
    gom_.Draw(render_window);
    render_window.draw(titleText_);
}

void SceneTitle::AddGameObject(GameObject* gameObject)
{
    gom_.Add(gameObject);
}

void SceneTitle::AddParticleEffect(const int& effect, const sf::Vector2f position)
{}

GameObject* SceneTitle::FindGameObject(const std::string& string, const bool byName, const bool byTag, const bool byID)
{//if byTag and byID are both left to default (false), search by name
    return gom_.Find(string, byName, byTag, byID); //returns a GameObject, returns a nullptr if the GameObject is not found
}

void SceneTitle::SortGameObjects()
{
    gom_.SortByLayers();
}

sf::View* SceneTitle::FindView(const std::string& viewName)
{
    return game_->GetCamera()->GetView(viewName);
}

void SceneTitle::SetOutcome(const bool outcome)
{}

void SceneTitle::ChangeScene(const std::string& sceneName)
{
    game_->ChangeScene(sceneName);
}

void SceneTitle::End()
{
    gom_.Clear();
}