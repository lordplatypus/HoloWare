#include "../Header/SceneTitle.h"
#include "../Header/LP.h"
#include "../Header/ID.h"

SceneTitle::SceneTitle(Game* game) : game_{game}
{}

SceneTitle::~SceneTitle()
{}

void SceneTitle::Init()
{
    game_->GetMiniGameManager()->Reset();

    titleText_ = LP::SetText("HoloWare", game_->GetCamera()->GetCameraCenter(), 128);
    LP::SetTextOriginCenter(titleText_);
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

void SceneTitle::Draw()
{
    gom_.Draw();
    LP::DrawText(titleText_);
}

void SceneTitle::AddGameObject(GameObject* gameObject)
{
    gom_.Add(gameObject);
}

void SceneTitle::OnWin()
{}

void SceneTitle::OnLoss()
{}

void SceneTitle::ChangeScene(const std::string& sceneName)
{
    game_->ChangeScene(sceneName);
}

void SceneTitle::End()
{
    gom_.Clear();
    LP::DeleteText(titleText_);
}