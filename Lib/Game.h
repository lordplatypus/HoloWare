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
    //Update Game
    void Update(float delta_time);
    //Draw Game
    void Draw(sf::RenderWindow& render_window);
    //Get Camera
    Camera* GetCamera();
    //Add a Scene to the scene map
    void AddScene(const std::string& name, Scene* scene);
    //Switch to a different scene
    void ChangeScene(const std::string& newScene);
    //End a scene
    void EndScene();

    //MiniGame Management
    MiniGameManager& GetMiniGameManager();

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