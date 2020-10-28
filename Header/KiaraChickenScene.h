#ifndef KIARA_CHICKEN_SCENE_H_
#define KIARA_CHICKEN_SCENE_H_
#include "Scene.h"
#include "Game.h"
#include "GameObjectManager.h"

class KiaraChickenScene : public Scene
{
public:
    KiaraChickenScene(Game* game);
    ~KiaraChickenScene();
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
};

#endif