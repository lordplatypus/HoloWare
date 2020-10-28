#ifndef SCENE_Title_H_
#define SCENE_Title_H_
#include "Scene.h"
#include "Game.h"
#include "GameObjectManager.h"

class SceneTitle : public Scene
{
public:
    SceneTitle(Game* game);
    ~SceneTitle();
    virtual void Init() override;
    virtual void Update(float delta_time) override;
    virtual void Draw() override;
    virtual void AddGameObject(GameObject* gameObject) override;
    virtual void OnWin() override;
    virtual void OnLoss() override;
    virtual void ChangeScene(const std::string& sceneName) override;
    virtual void End() override;

private:
    Game* game_{nullptr};
    GameObjectManager gom_;
    int background_{0};
    int titleText_{0};
};

#endif