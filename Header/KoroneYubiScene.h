#ifndef KORONE_YUBI_SCENE_H_
#define KORONE_YUBI_SCENE_H_
#include "Scene.h"
#include "Game.h"
#include "GameObjectManager.h"
#include "ID.h"
#include "KoroneYubiManager.h"

class KoroneYubiScene : public Scene
{
public:
    KoroneYubiScene(Game* game);
    ~KoroneYubiScene();
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
    KoroneYubiManager* kym_{nullptr};
    int difficulty_{medium_difficulty};
    int text_{0};
    int textAlpha_{255};
    float textTimer_{0.1f};
};

#endif