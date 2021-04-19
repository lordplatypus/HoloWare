#ifndef KORONE_YUBI_SCENE_H_
#define KORONE_YUBI_SCENE_H_
#include "../Lib/Scene.h"
#include "../Lib/Game.h"
#include "../Lib/GameObjectManager.h"
#include "../Lib/ID.h"
#include "KoroneYubiManager.h"

class KoroneYubiScene : public Scene
{
public:
    KoroneYubiScene(Game* game);
    ~KoroneYubiScene();
    virtual void Init() override;
    virtual void Update(float delta_time) override;
    virtual void Draw(sf::RenderWindow& render_window) const override;
    virtual void AddGameObject(GameObject* gameObject) override;
    virtual GameObject* FindGameObject(const std::string& string, const bool byName = true, const bool byTag = false, const bool byID = false) override;
    virtual void SortGameObjects() override;
    virtual sf::View* FindView(const std::string& viewName) override;
    virtual void SetOutcome(const bool outcome) override;
    virtual void ChangeScene(const std::string& sceneName) override;
    virtual void End() override;

private:
    Game* game_{nullptr};
    GameObjectManager gom_;
    //KoroneYubiManager* kym_{nullptr};
    int difficulty_{medium_difficulty};
    sf::Text text_;
    int textAlpha_{255};
    float textTimer_{0.1f};

    //Scene transition
    bool changeScene_{false};
};

#endif