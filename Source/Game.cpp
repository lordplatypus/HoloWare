#include <SFML/Graphics.hpp>
#include <string>
#include "../Header/Game.h"
#include "../Header/ID.h"
#include "../Header/SceneNull.h"
#include "../Header/SceneTitle.h"
#include "../Header/SceneMiniGame.h"
#include "../Header/SceneKiaraMiniGame.h"

static SceneNull nullScene;

Game::Game(Camera* camera) : camera_{camera}, scene_{&nullScene}
{
    loadImage_.Load();

    AddScene("Title", new SceneTitle(this));
    AddScene("MiniGame", new SceneMiniGame(this));
    AddScene("KiaraMiniGame", new SceneKiaraMiniGame(this));

    scene_ = scenes_["Title"];
    scene_->Init();
}

Game::~Game()
{
    Clear();
}

void Game::Update(float delta_time)
{
    scene_->Update(delta_time);
}

void Game::Draw()
{
    scene_->Draw();
}

void Game::AddScene(const std::string& name, Scene* scene)
{
    scenes_[name] = scene;
}

void Game::ChangeScene(const std::string& newScene)
{
    EndScene();
    scene_ = scenes_[newScene];
    scene_->Init();
}

void Game::EndScene()
{
    scene_->End();
    scene_ = &nullScene;
}

int Game::GetMiniGameCount() const
{
    return scenes_.size() - 2;
}

Camera* Game::GetCamera()
{
    return camera_;
}

void Game::PlayMusic(const int musicID, const bool loop)
{
    musicPlayer_.PlayMusic(musicID, loop);
}

void Game::Clear()
{
    scene_->End();

    for (auto pair : scenes_)
    {
        delete pair.second;
    }
    scenes_.clear();
}