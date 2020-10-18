#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_
#include <SFML/Graphics.hpp>
#include "Scene.h"

class Scene;

class GameObject
{
public:
    GameObject();
    virtual ~GameObject();

    virtual void Update(float delta_time);
    virtual void Draw();

    virtual void ReactOnCollision(GameObject& other);
    virtual void TakeDamage(const int damage);
    virtual void Kill();

    void StorePosition();
    int GetLeft() const;
    void SetLeft(const int left);
    int GetRight() const;
    void SetRight(const int right);
    int GetTop() const;
    void SetTop(const int top);
    int GetBottom() const;
    void SetBottom(const int bottom);
    const std::vector<sf::Vector2f> GetHitBox();
    bool IsCollision(GameObject& other);
    void OnCollision(GameObject& other);

    sf::Vector2f GetPosition() const;
    sf::Vector2f GetPrevPosition() const;
    virtual bool IsDead() const;
    const std::string& GetTag() const;
    const std::string& GetName() const;
    int GetID() const;

    GameObject(const GameObject& other) = delete;
    GameObject& operator = (const GameObject& other) = delete;

protected:
    Scene* scene_{nullptr};
    sf::Vector2f position_{0.0f, 0.0f};
    sf::Vector2f velocity_{0.0f, 0.0f};
    sf::Vector2f prevPosition_{0.0f, 0.0f};
    bool isDead_{false};

    int sprite_{0};
    int imageWidth_{0};
    int imageHeight_{0};
    int left_{0};
    int right_{0};
    int top_{0};
    int bottom_{0};

    std::string tag_{""};
    std::string name_{""};
    int ID_{0};
};

#endif