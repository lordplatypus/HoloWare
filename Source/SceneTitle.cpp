#include "../Header/SceneTitle.h"
#include "../Header/LP.h"
#include "../Header/ID.h"

SceneTitle::SceneTitle(Game* game) : game_{game}
{}

SceneTitle::~SceneTitle()
{}

void SceneTitle::Init()
{
    
}

void SceneTitle::Update(float delta_time)
{
    gom_.Update(delta_time);
    gom_.Collision();
    gom_.Remove();
}

void SceneTitle::Draw()
{
    gom_.Draw();
}

void SceneTitle::AddGameObject(GameObject* gameObject)
{
    gom_.Add(gameObject);
}

void SceneTitle::ChangeScene(const std::string& sceneName)
{
    game_->ChangeScene(sceneName);
}

void SceneTitle::End()
{
    gom_.Clear();
}