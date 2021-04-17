#include "Math.h"
#include <SFML/Graphics.hpp>
#include <cmath>

Math::Math()
{}

Math::~Math()
{}

float Math::PI()
{
    return M_PI;
}

sf::Vector2f Math::Lerp(sf::Vector2f v0, sf::Vector2f v1, float t)
{
    return (1 - t) * v0 + t * v1;
}

float Math::Lerp(float a, float b, float t)
{
    return a + (b - a) * t;
}