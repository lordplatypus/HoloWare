#ifndef SCENE_KIARA_MINI_GAME_H_
#define SCENE_KIARA_MINI_GAME_H_
#include "Scene.h"
#include "Game.h"
#include "GameObjectManager.h"

class SceneKiaraMiniGame : public Scene
{
public:
    SceneKiaraMiniGame(Game* game);
    ~SceneKiaraMiniGame();
    virtual void Init() override;
    virtual void Update(float delta_time) override;
    virtual void Draw() override;
    virtual void AddGameObject(GameObject* gameObject) override;
    virtual void OnWin() override;
    virtual void ChangeScene(const std::string& sceneName) override;
    virtual void End() override;

private:
    Game* game_{nullptr};
    GameObjectManager gom_;
    int background_{0};
};

#endif