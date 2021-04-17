#ifndef GAME_H_
#define GAME_H_
#include <unordered_map>
#include "Scene.h"
#include "LoadAssets.h"
#include "Camera.h"
#include "MiniGameManager.h"

class Game
{
public:
    Game(Camera* camera);
    ~Game();
    void Update(float delta_time);
    void Draw();

    //Scene Management
    void AddScene(const std::string& name, Scene* scene);
    void ChangeScene(const std::string& newScene);
    void EndScene();

    //MiniGame Management
    MiniGameManager* GetMiniGameManager();

    //Camera
    Camera* GetCamera();

    //Deletes pointers and whatnot at game close
    void Clear();

    Game(const Game& other) = delete;
    Game& operator = (const Game& other) = delete;

private:
    Camera* camera_{nullptr};
    std::unordered_map<std::string, Scene*> scenes_;
    Scene* scene_ {nullptr};
    LoadAssets loadAssets_;
    MiniGameManager miniGameManager_;

    bool win_{true};
};

#endif