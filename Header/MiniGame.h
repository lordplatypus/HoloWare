#ifndef MINI_GAME_H_
#define MINI_GAME_H_
#include "GameObject.h"
#include "GameObjectManager.h"

class MiniGame
{
public:
    MiniGame();
    ~MiniGame();
    virtual void Update(float delta_time);
    virtual void Draw();

    void AddGameObject(GameObject* gameObject);
    GameObject* FindGameObjectByTag(const std::string& tag);
    GameObject* FindGameObjectByName(const std::string& name);

    bool IsClear() const;

protected:
    GameObjectManager gom_;
    bool clear_{false};
};

#endif