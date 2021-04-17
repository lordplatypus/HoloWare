#ifndef MATH_H_
#define MATH_H_
#include <SFML/Graphics.hpp>

class Math
{
public:
    Math();
    ~Math();
    float PI();
    sf::Vector2f Lerp(sf::Vector2f v0, sf::Vector2f v1, float t);
    float Lerp(float a, float b, float t);
};

#endif