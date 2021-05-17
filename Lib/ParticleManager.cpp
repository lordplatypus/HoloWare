#include <SFML/Graphics.hpp>
#include "LP.h"
#include "ParticleManager.h"
#include "ID.h"
#include "Math.h"

ParticleManager::ParticleManager()
{}

ParticleManager::~ParticleManager()
{}

void ParticleManager::Money(const sf::Vector2f& position, Scene* scene)
{
    int randNum = rand() % 3 + 1;
    for (int i = 0; i < randNum; i++)
    {
        sf::Sprite sprite = LP::SetSprite(kiara_chicken_cash_image);
        sf::Vector2f position_ = position;
        position_.x += (rand() % 30);
        position_.y += (rand() % 10);
        float vx = (rand() % 100) - 50;
        float vy = -(rand() % 50) - 50;
        float lifespan = (rand() % 10 + 20) / 10.0f;
        float angle = (rand() % 720) - 360;
        float angleV = (rand() % 250) - 500;
        scene->AddGameObject(new Particle(sprite, position_.x, position_.y, vx, vy, 1, lifespan, 0, 100.0f, angle, angleV, 0.5f, 0.5f, 255, 255, 255, 255, 0));
    }
    randNum = rand() % 3 + 1;
    for (int i = 0; i < randNum; i++)
    {
        sf::Sprite sprite = LP::SetSprite(kiara_chicken_silver_coin_image);
        LP::SetSpriteOriginCenter(&sprite);
        sf::Vector2f position_ = position;
        position_.x += (rand() % 30);
        position_.y += (rand() % 10);
        float vx = (rand() % 100) - 50;
        float vy = -(rand() % 50) - 50;
        float lifespan = (rand() % 10 + 20) / 10.0f;
        float angle = (rand() % 720) - 360;
        float angleV = (rand() % 250) - 500;
        scene->AddGameObject(new Particle(sprite, position_.x, position_.y, vx, vy, 1, lifespan, 0, 100.0f, angle, angleV, 0.5f, 0.5f, 255, 255, 255, 255, 0));
    }
    randNum = rand() % 3 + 1;
    for (int i = 0; i < randNum; i++)
    {
        sf::Sprite sprite = LP::SetSprite(kiara_chicken_bronze_coin_image);
        LP::SetSpriteOriginCenter(&sprite);
        sf::Vector2f position_ = position;
        position_.x += (rand() % 30);
        position_.y += (rand() % 10);
        float vx = (rand() % 100) - 50;
        float vy = -(rand() % 50) - 50;
        float lifespan = (rand() % 10 + 20) / 10.0f;
        float angle = (rand() % 720) - 360;
        float angleV = (rand() % 250) - 500;
        scene->AddGameObject(new Particle(sprite, position_.x, position_.y, vx, vy, 1, lifespan, 0, 100.0f, angle, angleV, 0.5f, 0.5f, 255, 255, 255, 255, 0));
    }
}

void ParticleManager::Sweat(const sf::Vector2f& position, Scene* scene)
{
    int randNum = rand() % 3 + 1;
    for (int i = 0; i < randNum; i++)
    {
        sf::Sprite sprite = LP::SetSprite(kiara_chicken_sweat_image);
        sf::Vector2f position_ = position;
        position_.x += (rand() % 10) - 20;
        position_.y += (rand() % 10) - 20;
        float vx = -(rand() % 50) - 10;
        float vy = (rand() % 20) + 50;
        float lifespan = (rand() % 4 + 7) / 10.0f;
        float angle = (rand() % 30) + 30;
        float angleV = -(rand() % 100);
        scene->AddGameObject(new Particle(sprite, position_.x, position_.y, vx, vy, 1, lifespan, 0, 0, angle, angleV, 0.5f, 0.5f, 255, 255, 255, 255, 0));
    }
}