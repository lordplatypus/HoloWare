#ifndef KORONE_YUBI_HAND_H_
#define KORONE_YUBI_HAND_H_
#include "../Lib/GameObject.h"
#include "KoroneYubiManager.h"

class KoroneYubiHand : public GameObject
{
public:
    KoroneYubiHand(sf::Vector2f position, int ID, KoroneYubiManager* kym, Scene* scene);
    ~KoroneYubiHand();
    void Update(float delta_time) override;
    void Draw() override;

private:
    void InputHandle();

private:
    KoroneYubiManager* kym_{nullptr};
    bool spacePressed_{true};
    int frame_{0};
    std::vector<int> sprites_;
};

#endif