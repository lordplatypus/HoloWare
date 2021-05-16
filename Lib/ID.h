#ifndef ID_H_
#define ID_H_

enum //Images
{
    ina_transition_hp_image,
    ina_transition_door_image,
    ina_transition_background_image,
    ina_transition_loading_image,
    ina_transition_timer_end_image,
    ina_transition_timer_segment_image,
    ina_transition_timer_bomb_image,
    transition_explosion_image,

    kiara_chicken_kiara_image,
    kiara_chicken_background_image,
    kiara_chicken_chicken_image,
    kiara_chicken_rock_image,
    kiara_chicken_shadow_image,
    kiara_chicken_cash_image,
    kiara_chicken_silver_coin_image,
    kiara_chicken_bronze_coin_image,
    kiara_chicken_people_image,
    kiara_chicken_sweat_image,
    kiara_chicken_bucket_image,
    kiara_chicken_register_image,

    korone_yubi_left_hand_image,
    korone_yubi_right_hand_image,
    korone_yubi_stream_image,
    korone_yubi_laugh1_image,
    korone_yubi_laugh2_image,
    korone_yubi_chat_image,
};

enum //Music
{
    kiara_theme
};

enum //Sound Effects
{
    pop_se,
    squeek_se,
    whoosh_se,
    thud_se,
    win_se,
    lose_se
};

enum //Difficulty
{
    easy_difficulty,
    medium_difficulty,
    hard_difficulty
};

enum Scenes//Scenes
{
    title_scene,
    minigame_scene,
    kiara_minigame
};

enum //Render Layer
{
    background_layer,
    main_layer,
    minigame_UI_layer,
    timer_layer,
    transition_layer,
    UI_layer
};

enum //Particle Effects
{
    money_effect
};

#endif 