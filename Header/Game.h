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

    //Scene Management
    void AddScene(const std::string& name, Scene* scene);
    void ChangeScene(const std::string& newScene);
    void EndScene();

    //MiniGame Management
    int GetMiniGameCount() const;
    void SetWin(const bool win);
    bool GetWin() const;

    //Camera
    Camera* GetCamera();

    //Music and Sound Effects
    void PlayMusic(const int musicID, const bool loop);

    //Deletes pointers and whatnot at game close
    void Clear();

    Game(const Game& other) = delete;
    Game& operator = (const Game& other) = delete;

private:
    Camera* camera_{nullptr};
    std::unordered_map<std::string, Scene*> scenes_;
    Scene* scene_ {nullptr};
    LoadImage loadImage_;
    MusicPlayer musicPlayer_;

    bool win_{true};
};

#endif