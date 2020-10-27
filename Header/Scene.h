#ifndef SCENE_H_
#define SCENE_H_
#include <string>
#include "GameObject.h"

class GameObject;

class Scene
{
public:
    //Scene();
    virtual ~Scene() = default;
    virtual void Init() = 0;
    virtual void Update(float delta_time) = 0;
    virtual void Draw() = 0;
    virtual void AddGameObject(GameObject* gameObject) = 0;
    virtual void OnWin() = 0;
    virtual void ChangeScene(const std::string& sceneName) = 0;
    virtual void End() = 0;
};

#endif