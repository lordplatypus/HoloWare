#ifndef KORONE_YUBI_HAND_H_
#define KORONE_YUBI_HAND_H_
#include "../Lib/GameObject.h"

class KoroneYubiHand : public GameObject
{
public:
    KoroneYubiHand(sf::Vector2f position, Scene* scene, int maxHands, int num = 0);
    ~KoroneYubiHand();
    void Update(float delta_time) override;
    void Draw(sf::RenderWindow& render_window) const override;

    void SetActive();

private:
    void InputHandle();

private:
    int frame_{0};
    std::vector<sf::Sprite> sprites_;
    bool active_{false}; //current active hand
    KoroneYubiHand* nextHand_{nullptr}; //next hand
    int maxHands_{0}; //increases with difficulty
};

#endif