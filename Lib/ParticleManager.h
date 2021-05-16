#ifndef PARTICLE_MANAGER_H_
#define PARTICLE_MANAGER_H_
#include <vector>
#include "Particle.h"
#include "Scene.h"

class ParticleManager
{
public:
    ParticleManager(Scene* scene);
    ~ParticleManager();
    //void Update(float delta_time);
    //void Draw(sf::RenderWindow& render_window) const;
    void Add(const int& effect, const sf::Vector2f& position);

    void Money(const sf::Vector2f& position);
    
    void Explosion(float x, float y);
    void SquareExplosion(float x, float y);
    void WhiteOut(float x, float y);
    void FadeToBlack(float x, float y);
    void FadeFromBlack(float x, float y);
    void SmokeScreen(float x, float y);
    void Sparkle(float x, float y);

    //void Clear();

private:
    Scene* scene_{nullptr};
    //std::vector<Particle*> particles;
};

#endif