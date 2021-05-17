#include <iostream>
#include <SFML/Graphics.hpp>
#include "LoadAssets.h"
#include "ID.h"
#include "LP.h"
#include "MP.h"

LoadAssets::LoadAssets()
{}

LoadAssets::~LoadAssets()
{}

void LoadAssets::Load()
{
    LoadImage();
    LoadSound();
}

void LoadAssets::LoadImage()
{
    LP::SetFont("./Resource/Kiara/Blue Sky 8x8.ttf");
    LP::SetTexture(ina_transition_hp_image, "./Resource/Transition/Ina/Tako.png", 256, 64);
    LP::SetTexture(ina_transition_door_image, "./Resource/Transition/Ina/InaDoor.png", 240, 270);
    LP::SetTexture(ina_transition_background_image, "./Resource/Transition/Ina/InaBackground.png", 480, 270);
    LP::SetTexture(ina_transition_loading_image, "./Resource/Transition/Ina/InaLoading.png", 320, 32);
    LP::SetTexture(ina_transition_timer_end_image, "./Resource/Transition/Ina/InaTimerEnd.png", 64, 64);
    LP::SetTexture(ina_transition_timer_bomb_image, "./Resource/Transition/Ina/InaTimerBomb.png", 64, 64);
    LP::SetTexture(ina_transition_timer_segment_image, "./Resource/Transition/Ina/InaTimerSegment.png", 128, 64);
    LP::SetTexture(transition_explosion_image, "./Resource/Transition/Explosion.png", 128, 128);

    // LP::SetTexture(kiara_chicken_kiara_image, "./Resource/Kiara/Kiara.png", 1142, 1043);
    // LP::SetTexture(kiara_chicken_background_image, "./Resource/Kiara/Background.png", 1920, 1080);
    // LP::SetTexture(kiara_chicken_chicken_image, "./Resource/Kiara/Chicken.png", 59, 90);
    // LP::SetTexture(kiara_chicken_rock_image, "./Resource/Kiara/rock.png", 90, 61);
    // LP::SetTexture(kiara_chicken_shadow_image, "./Resource/Kiara/Shadow.png", 448, 99);

    LP::SetTexture(kiara_chicken_kiara_image, "./Resource/Kiara/Kiara_Minigame.png", 52, 50);
    LP::SetTexture(kiara_chicken_bucket_image, "./Resource/Kiara/Kiara_Bucket.png", 55, 14);
    LP::SetTexture(kiara_chicken_shadow_image, "./Resource/Kiara/Kiara_Shadow.png", 26, 5);
    LP::SetTexture(kiara_chicken_sweat_image, "./Resource/Kiara/Kiara_Sweat.png", 8, 11);
    LP::SetTexture(kiara_chicken_background_image, "./Resource/Kiara/Kiara_Background.png", 480, 270);
    LP::SetTexture(kiara_chicken_chicken_image, "./Resource/Kiara/Kiara_Chicken.png", 8, 5);
    LP::SetTexture(kiara_chicken_rock_image, "./Resource/Kiara/Kiara_Rock.png", 8, 5);
    LP::SetTexture(kiara_chicken_cash_image, "./Resource/Kiara/Kiara_Cash.png", 20, 10);
    LP::SetTexture(kiara_chicken_silver_coin_image, "./Resource/Kiara/Kiara_Silver_Coin.png", 3, 3);
    LP::SetTexture(kiara_chicken_bronze_coin_image, "./Resource/Kiara/Kiara_Bronze_Coin.png", 3, 3);
    LP::SetTexture(kiara_chicken_register_image, "./Resource/Kiara/Kiara_Register.png", 671, 42);
    LP::SetTexture(kiara_chicken_people_image, "./Resource/Kiara/Kiara_People.png", 128, 50);
    
    LP::SetTexture(korone_yubi_left_hand_image, "./Resource/Korone/LeftHand.png", 408, 64);
    LP::SetTexture(korone_yubi_right_hand_image, "./Resource/Korone/RightHand.png", 408, 64);
    LP::SetTexture(korone_yubi_stream_image, "./Resource/Korone/Korone_Stream.png", 480, 270);
    LP::SetTexture(korone_yubi_laugh1_image, "./Resource/Korone/Korone_Laugh1.png", 16, 28);
    LP::SetTexture(korone_yubi_laugh2_image, "./Resource/Korone/Korone_Laugh2.png", 31, 22);
    LP::SetTexture(korone_yubi_chat_image, "./Resource/Korone/Korone_Chat.png", 525, 44);
}

void LoadAssets::LoadSound()
{
    MP::SetMusic(kiara_theme, "./Resource/Kiara/Kiara_Loading_Song.ogg");
    MP::SetSound(pop_se, "./Resource/Korone/pop.ogg");
    MP::SetSound(squeek_se, "./Resource/Korone/squeek.wav");
    MP::SetSound(whoosh_se, "./Resource/Transition/door_movement.wav");
    MP::SetSound(thud_se, "./Resource/Transition/door_impact.wav");
    MP::SetSound(lose_se, "./Resource/Transition/jingle_lose.wav");
    MP::SetSound(win_se, "./Resource/Transition/jingle_win.wav");
}