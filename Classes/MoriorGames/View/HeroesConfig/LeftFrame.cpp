#include "LeftFrame.h"
#include "../Custom/PopupBattleHero.h"
#include "../../Services/SoundPlayer.h"
#include "../../Vendor/Containers/HeroesConfig.h"
#include "../../Vendor/Repository/HeroRepository.h"
#include "../../Vendor/Utils/TextUtils.h"

LeftFrame::LeftFrame(Layer *layer, HeroesConfigPublisher *publisher)
    : AbstractFrame(layer), publisher{publisher}
{
    addView();
    addHeroesList();
    frame->addChild(scrollView);
}

void LeftFrame::update(HeroConfigPayload *)
{
    scrollView->removeAllChildren();
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
    std::vector<Hero *> heroes;
    for (auto hero:heroRepo->findAll()) {
        if (!hero->isNexus()) {
            heroes.push_back(hero);
        }
    }

    int index = 0;
    for (auto hero:heroes) {
        if (heroesConfig->hasHero(hero)) {
            auto heroWithSkills = getHeroWithSkills(hero);
            auto sprite = heroRow(index, heroWithSkills);
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
}

ui::Button *LeftFrame::getUpgradeButton(Hero *hero)
{
    auto button = createInfoButton("battle_heroes_upgrade");
    button->addTouchEventListener(
        [&, hero, this](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                SoundPlayer::playEffect("sounds/button.mp3");
                bool canImprove = true;
                new PopupBattleHero(layer, publisher, hero, canImprove);
            }
        });

    return button;
}

ui::Button *LeftFrame::getActionButton(Hero *hero)
{
    auto button = createActionButton("battle_heroes_remove");
    button->addTouchEventListener(
        [&, hero, this](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                publisher->notifyObservers(
                    new HeroConfigPayload(HeroConfigPayload::REMOVE, hero)
                );
                SoundPlayer::playEffect("sounds/button.mp3");
            }
        });

    return button;
}
