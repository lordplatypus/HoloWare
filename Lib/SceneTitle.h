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
    sf::Sprite background_;
    sf::Text titleText_;
};

#endif