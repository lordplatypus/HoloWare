#ifndef SCENE_NULL_H_
#define SCENE_NULL_H_
#include "Scene.h"

class SceneNull : public Scene
{
public:
    virtual void Init() override {}
    virtual void Update(float delta_time) override {}
    virtual void Draw() override {}
    virtual void AddGameObject(GameObject* gameObject) override {}
    virtual void OnWin() override {}
    virtual void OnLoss() override {}
    virtual void ChangeScene() override {}
    virtual void End() override {}
};

#endif