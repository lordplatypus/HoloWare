#ifndef GAMEOBJECT_MANAGER_H_
#define GAMEOBJECT_MANAGER_H_
#include <list>
#include "GameObject.h"

class GameObjectManager
{
public:
    GameObjectManager();
    ~GameObjectManager();
    void Add(GameObject* gameObject);
    void Update(float delta_time);
    void Draw() const;
    void Collision();
    void Remove();
    GameObject* Find(const std::string& name) const;
    void Clear();

    GameObjectManager(const GameObjectManager& other) = delete;
    GameObjectManager& operator = (const GameObjectManager& other) = delete;

private:
    std::list<GameObject*> gameObjects_;
};

#endif