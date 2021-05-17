#ifndef KIARA_SCENE_H_
#define KIARA_SCENE_H_
#include "../Lib/Scene.h"
#include "../Lib/Game.h"
#include "../Lib/GameObjectManager.h"
#include "../Lib/ParticleManager.h"

#include "Register.h"
#include "BackgroundPeople.h"

class KiaraScene : public Scene
{
public:
    KiaraScene(Game* game);
    ~KiaraScene();
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
    ParticleManager pm_;

    //Scene transition
    bool changeScene_{false};

    //Text
    sf::Text text_;
    int textAlpha_{255};
    float textTimer_{0.1f};

    //objects
    std::vector<Register*> register_;
    std::vector<BackgroundPeople*> people_;
};

#endif