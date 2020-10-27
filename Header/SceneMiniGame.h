#ifndef SCENE_MINI_GAME_H_
#define SCENE_MINI_GAME_H_
#include "Scene.h"
#include "Game.h"
#include "GameObjectManager.h"

class SceneMiniGame : public Scene
{
public:
    SceneMiniGame(Game* game);
    ~SceneMiniGame();
    virtual void Init() override;
    void Reset();
    virtual void Update(float delta_time) override;
    virtual void Draw() override;
    virtual void AddGameObject(GameObject* gameObject) override;
    virtual void OnWin() override;
    virtual void ChangeScene(const std::string& sceneName) override;
    virtual void End() override;

private:
    void RandomMiniGame();

private:
    Game* game_{nullptr};
    GameObjectManager gom_;

    //Images
    int background_{0};
    int backgroundDetail_{0};

    //Text
    int timerText_{0};

    //Variables
    int hp_{4};
    float timer_{0.0f};
    sf::Vector2f velocity_{10.0f, 0.0f};

    //States
    enum State
    {
        First,
        Second,
        Third
    };
    State state_{First};
};

#endif