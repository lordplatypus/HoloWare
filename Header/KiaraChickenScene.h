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
    virtual void ChangeScene() override;
    virtual void End() override;

private:
    Game* game_{nullptr};
    GameObjectManager gom_;
    int background_{0};

    //Scene transition
    bool changeScene_{false};

    //Text
    int text_{0};
    int textAlpha_{255};
    float textTimer_{0.1f};
};

#endif