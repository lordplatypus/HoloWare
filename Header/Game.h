#ifndef GAME_H_
#define GAME_H_
#include <unordered_map>
#include "Scene.h"
#include "LoadImage.h"
#include "MusicPlayer.h"
#include "Camera.h"

class Game
{
public:
    Game(Camera* camera);
    ~Game();
    void Update(float delta_time);
    void Draw();
    void AddScene(const std::string& name, Scene* scene);
    void ChangeScene(const std::string& newScene);
    void EndScene();
    int GetMiniGameCount() const;
    Camera* GetCamera();
    void PlayMusic(const int musicID, const bool loop);
    void Clear();

    Game(const Game& other) = delete;
    Game& operator = (const Game& other) = delete;

private:
    Camera* camera_{nullptr};
    std::unordered_map<std::string, Scene*> scenes_;
    Scene* scene_ {nullptr};
    LoadImage loadImage_;
    MusicPlayer musicPlayer_;
};

#endif