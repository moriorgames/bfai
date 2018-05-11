#include "LeftFrame.h"
#include "../Custom/PopupBattleHero.h"
#include "../../Scenes/HeroesConfigScene.h"
#include "../../Services/SoundPlayer.h"
#include "../../Vendor/Containers/HeroesConfig.h"
#include "../../Vendor/Repository/HeroRepository.h"
#include "../../Vendor/Utils/TextUtils.h"

LeftFrame::LeftFrame(Layer *layer)
    : AbstractFrame(layer)
{
    addView();
    addHeroesList();
}

void LeftFrame::addView()
{
    auto frame = initFrame();
    frame->setPositionX(centerPosition.x - FRAME_X * scale);
    layer->addChild(frame, Z_ORDER_BACKGROUND);
    initScrollView();
}

void LeftFrame::addHeroesList()
{
    auto heroes = heroRepo->findAll();

    int index = 0;
    for (auto hero:heroes) {
        if (heroesConfig->hasHero(hero)) {
            auto sprite = heroRow(index, hero);
            if (hero->isEnabled()) {
                sprite->addChild(
                    getUpgradeButton(hero)
                );
                sprite->addChild(
                    getActionButton(hero)
                );
            }
            scrollView->addChild(sprite);
            index++;
        }
    }

    frame->addChild(scrollView);
}

ui::Button *LeftFrame::getUpgradeButton(Hero *hero)
{
    auto button = createInfoButton("battle_heroes_upgrade");
    button->addTouchEventListener(
        [&, hero](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                SoundPlayer::playEffect("sounds/button.mp3");
                bool canImprove = true;
                new PopupBattleHero(layer, hero, canImprove);
            }
        });

    return button;
}

ui::Button *LeftFrame::getActionButton(Hero *hero)
{
    auto button = createActionButton("battle_heroes_remove");
    button->addTouchEventListener(
        [&, hero](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                heroesConfig->removeHero(hero);
                SoundPlayer::playEffect("sounds/button.mp3");
                auto scene = HeroesConfigScene::createScene();
                Director::getInstance()->replaceScene(scene);
            }
        });

    return button;
}
