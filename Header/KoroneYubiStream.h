#ifndef KORONE_YUBI_STREAM_H_
#define KORONE_YUBI_STREAM_H_
#include "GameObject.h"

class KoroneYubiStream : public GameObject
{
public:
    KoroneYubiStream(sf::Vector2f position, Scene* scene);
    ~KoroneYubiStream();
    void Update(float delta_time) override;
    void Draw() override;

private:
    void ChatHandle(float delta_time);
    void LaughHandle(float delta_time);

private:
    //sprites
    int streamSprite_{0};
    int laugh1Sprite_{0};
    int laugh2Sprite_{0};
    bool laughFrame_{false};
    std::vector<int> chatSprite_;
    int chatFrame_{0};

    //timer
    float laughTimer_{0.0f};
    float chatTimer_{0.0f};
};

#endif