#include <SFML/Graphics.hpp>
#include <string>
#include "../Header/Game.h"
#include "../Header/ID.h"
#include "../Header/SceneNull.h"
#include "../Header/SceneTitle.h"
#include "../Header/InaTransitionScene.h"
#include "../Header/KiaraChickenScene.h"
#include "../Header/KoroneYubiScene.h"

static SceneNull nullScene;

Game::Game(Camera* camera) : camera_{camera}, scene_{&nullScene}
{
    srand(time(NULL)); //random seed
    loadImage_.Load();

    AddScene("Title", new SceneTitle(this));
    AddScene("InaTransition", new InaTransitionScene(this));
    AddScene("KiaraChicken", new KiaraChickenScene(this));
    AddScene("KoroneYubi", new KoroneYubiScene(this));

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

MiniGameManager* Game::GetMiniGameManager()
{
    return &miniGameManager_;
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