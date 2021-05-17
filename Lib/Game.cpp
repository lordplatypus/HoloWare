#include <SFML/Graphics.hpp>
#include <string>
#include "Game.h"
#include "ID.h"
#include "SceneNull.h"
#include "SceneTitle.h"
#include "IP.h"
#include "../Ina_Transition/InaTransitionScene.h"
#include "../Kiara_Loading_Minigame/KiaraScene.h"
#include "../Korone_Yubi_Minigame/KoroneYubiScene.h"

static SceneNull nullScene;

Game::Game(Camera* camera) : camera_{camera}, scene_{&nullScene}
{
    srand(time(NULL)); //random seed
    loadAssets_.Load();

    AddScene("Title", new SceneTitle(this));
    AddScene("InaTransition", new InaTransitionScene(this));
    AddScene("KiaraChicken", new KiaraScene(this));
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
    IP::Reset();
}

void Game::Draw(sf::RenderWindow& render_window)
{
    scene_->Draw(render_window);
}

Camera* Game::GetCamera()
{
    return camera_;
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

MiniGameManager& Game::GetMiniGameManager()
{
    return miniGameManager_;
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