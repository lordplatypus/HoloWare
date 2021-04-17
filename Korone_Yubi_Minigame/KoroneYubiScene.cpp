#include "KoroneYubiScene.h"
#include "../Lib/LP.h"
#include "KoroneYubiHand.h"
#include "KoroneYubiStream.h"
#include "../Ina_Transition/InaTransitionDoorOpen.h"
#include "../Ina_Transition/InaTransitionTimer.h"

KoroneYubiScene::KoroneYubiScene(Game* game) : game_{game}
{}

KoroneYubiScene::~KoroneYubiScene()
{}

void KoroneYubiScene::Init()
{
    kym_ = new KoroneYubiManager(this);

    game_->GetCamera()->SetCameraViewSize(480, 270);
    game_->GetCamera()->SetTarget(sf::Vector2f(480/2, 270/2));

    difficulty_ = game_->GetMiniGameManager()->GetDifficulty();
    for (int i = 0; i <= difficulty_; i++)
    {
        AddGameObject(new KoroneYubiHand(sf::Vector2f(game_->GetCamera()->GetCameraCenter().x - (136 * difficulty_)/2 - 68 + 136 * i, game_->GetCamera()->GetCameraBottomEdge() - 64*2), i, kym_, this));
    }
    kym_->SetDifficulty(difficulty_);
    textAlpha_ = 255;

    text_ = LP::SetText("Korone's stream is starting,\npay the yubi tax!", sf::Vector2f(game_->GetCamera()->GetCameraCenter().x, game_->GetCamera()->GetCameraCenter().y - 64), 64);
    LP::SetTextOriginCenter(text_);
    LP::SetTextScale(text_, .2f, .2f);

    AddGameObject(new InaTransitionTimer(sf::Vector2f(game_->GetCamera()->GetCameraLeftEdge(), game_->GetCamera()->GetCameraBottomEdge() - 32), 
                                         2.0f - game_->GetMiniGameManager()->GetTimerModifier(), game_->GetCamera(), this));

    AddGameObject(new InaTransitionDoorOpen(game_->GetCamera(), this));
}

void KoroneYubiScene::Update(float delta_time)
{
    gom_.Update(delta_time); //update all gameobjects
    gom_.Collision(); //check collision between gameobjects
    gom_.Remove(); //remove "dead" gameobjects

    if (textAlpha_ > 0) 
    {
        textTimer_ -= delta_time;
        if (textTimer_ < 0.0f)
        {
            textAlpha_ -= 10;
            if (textAlpha_ < 0) textAlpha_ = 0;
            LP::SetTextColor(text_, 255, 255, 255, textAlpha_);
            textTimer_ = 0.1f;
        }
    }

    if (changeScene_)
    {
        changeScene_ = false;
        OnLoss();
        game_->ChangeScene("InaTransition");
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        OnLoss();
        game_->ChangeScene("InaTransition");
    }
}

void KoroneYubiScene::Draw()
{
    gom_.Draw(); //Draw all gameobjects
    LP::DrawText(text_);
}

void KoroneYubiScene::AddGameObject(GameObject* gameObject)
{
    gom_.Add(gameObject); //add gameobject to the list of gameobjects
}

void KoroneYubiScene::OnWin()
{
    for (int i = 0; i <= difficulty_; i++)
    {
        gom_.Find(i)->Kill();
    }
    AddGameObject(new KoroneYubiStream(sf::Vector2f(0.0f, 0.0f), this));
    game_->GetMiniGameManager()->SetWin(true);
}

void KoroneYubiScene::OnLoss()
{
    if (game_->GetMiniGameManager()->GetWin()) return; //if already won the round don't null that win
    game_->GetMiniGameManager()->SetWin(false);
    game_->GetMiniGameManager()->DecrementHP();
}

void KoroneYubiScene::ChangeScene()
{
    changeScene_ = true;
}

void KoroneYubiScene::End()
{
    gom_.Clear();
    delete kym_;
}