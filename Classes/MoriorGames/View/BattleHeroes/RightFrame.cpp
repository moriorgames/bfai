#include "RightFrame.h"
#include "../../Scenes/BattleHeroesScene.h"
#include "../../Services/SoundPlayer.h"
#include "../../Vendor/Containers/BattleHeroesConfig.h"
#include "../../Vendor/Repository/HeroRepository.h"
#include "../../Vendor/Utils/TextUtils.h"

RightFrame::RightFrame(Layer *layer)
    : AbstractFrame(layer)
{
    addView();
    addHeroesList();
}

void RightFrame::addView()
{
    frame->setPositionX(centerPosition.x + FRAME_X * scale);
}

void RightFrame::addHeroesList()
{
    auto heroes = heroRepo->findAll();

    int index = 0;
    for (auto hero:heroes) {
        if (!battleHeroesConfig->hasHero(hero)) {
            auto sprite = heroRow(index, hero);
            sprite->addChild(
                getActionButton(hero)
            );
            scrollView->addChild(sprite);
            index++;
        }
    }

    frame->addChild(scrollView);
}

ui::Button *RightFrame::getActionButton(Hero *hero)
{
    auto button = ui::Button::create("ui/action-button.png", "", "");
    button->setAnchorPoint(Point(0, 0));
    button->setPosition(Point(COL_3, ROW_2));

    // Translator: translator->tr("menu_" + key)
    auto label = fontCreator->buttonLabel("Use", "fonts/buttons-label.otf", 50);
    button->setTitleLabel(label);
    button->addTouchEventListener(
        [&, hero](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                battleHeroesConfig->addHero(hero);
                SoundPlayer::playEffect("sounds/button.mp3");
                auto scene = BattleHeroesScene::createScene();
                Director::getInstance()->replaceScene(scene);
            }
        });

    return button;
}
