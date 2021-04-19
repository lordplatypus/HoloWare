#ifndef KORONE_YUBI_STREAM_H_
#define KORONE_YUBI_STREAM_H_
#include "../Lib/GameObject.h"

class KoroneYubiStream : public GameObject
{
public:
    KoroneYubiStream(sf::Vector2f position, Scene* scene);
    ~KoroneYubiStream();
    void Update(float delta_time) override;
    void Draw(sf::RenderWindow& render_window) const override;

private:
    void ChatHandle(float delta_time);
    void LaughHandle(float delta_time);

private:
    //sprites
    sf::Sprite streamSprite_;
    sf::Sprite laugh1Sprite_;
    sf::Sprite laugh2Sprite_;
    bool laughFrame_{false};
    std::vector<sf::Sprite> chatSprite_;
    int chatFrame_{0};

    //timer
    float laughTimer_{0.0f};
    float chatTimer_{0.0f};
};

#endif