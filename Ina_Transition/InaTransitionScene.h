#ifndef INA_TRANSITION_SCENE_H_
#define INA_TRANSITION_SCENE_H_
#include "../Lib/Scene.h"
#include "../Lib/Game.h"
#include "../Lib/GameObjectManager.h"

class InaTransitionScene : public Scene
{
public:
    InaTransitionScene(Game* game);
    ~InaTransitionScene();
    virtual void Init() override;
    void Reset();
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
    void RandomMiniGame();

private:
    Game* game_{nullptr};
    GameObjectManager gom_;

    //Images
    sf::Sprite background_;
    sf::Sprite backgroundDetail_;

    //Text
    sf::Text timerText_;
    sf::Text miniGameCountText_;

    //Variables
    float timer_{0.0f};
    sf::Vector2f velocity_{10.0f, 0.0f};

    //States
    enum State
    {
        WinState,
        LossState,
        DifficultyUp,
    };
    State state_{WinState};

    //Scene transition
    bool changeScene_{false};
};

#endif