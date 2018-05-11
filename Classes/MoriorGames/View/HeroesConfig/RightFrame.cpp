#include "RightFrame.h"
#include "../Custom/PopupBattleHero.h"
#include "../../Scenes/HeroesConfigScene.h"
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
    auto frame = initFrame();
    frame->setPositionX(centerPosition.x + FRAME_X * scale);
    layer->addChild(frame, Z_ORDER_BACKGROUND);
    initScrollView();
}

void RightFrame::addHeroesList()
{
    auto heroes = heroRepo->findAll();

    int index = 0;
    for (auto hero:heroes) {
        if (!battleHeroesConfig->hasHero(hero)) {
            auto sprite = heroRow(index, hero);
            if (hero->isEnabled()) {
                sprite->addChild(
                    getInfoButton(hero)
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

ui::Button *RightFrame::getInfoButton(Hero *hero)
{
    auto button = createInfoButton("battle_heroes_info");
    button->addTouchEventListener(
        [&, hero](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                SoundPlayer::playEffect("sounds/button.mp3");
                new PopupBattleHero(layer, hero);
            }
        });

    return button;
}

ui::Button *RightFrame::getActionButton(Hero *hero)
{
    auto button = createActionButton("battle_heroes_use");
    button->addTouchEventListener(
        [&, hero](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                battleHeroesConfig->addHero(hero);
                SoundPlayer::playEffect("sounds/button.mp3");
                auto scene = HeroesConfigScene::createScene();
                Director::getInstance()->replaceScene(scene);
            }
        });

    return button;
}
