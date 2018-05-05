#include "RightFrame.h"
#include "../../Vendor/Repository/HeroRepository.h"
#include "../../Vendor/Utils/TextUtils.h"

RightFrame::RightFrame(Layer *layer)
    : ViewHelper(layer)
{
    fontCreator = new FontCreator;

    addView();
    addHeroesList();
}

void RightFrame::addView()
{
    frame = Sprite::create("ui/frame-battle-heroes.png");
    frame->setScale(scale);
    frame->setPosition(centerPosition);
    frame->setPositionX(centerPosition.x + FRAME_X * scale);

    layer->addChild(frame, Z_ORDER_BACKGROUND);
}

void RightFrame::addHeroesList()
{
    auto heroes = heroRepo->findAll();
    scrollViewHeight = heroes.size() * SCROLL_VIEW_INNER_HEIGHT;

    scrollView = ui::ScrollView::create();
    scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
    scrollView->setScrollBarWidth(3);
    scrollView->setContentSize(Size(
        frame->getContentSize().width - SCROLL_VIEW_MARGIN,
        frame->getContentSize().height - SCROLL_VIEW_MARGIN
    ));
    scrollView->setInnerContainerSize(Size(
        frame->getContentSize().width - SCROLL_VIEW_MARGIN,
        scrollViewHeight
    ));
    scrollView->setPosition(Point(
        scrollView->getPosition().x + SCROLL_VIEW_MARGIN / 2,
        scrollView->getPosition().y + SCROLL_VIEW_MARGIN / 2
    ));
    scrollView->setBounceEnabled(true);

    int index = 0;
    for (auto hero:heroes) {
        addRow(index, hero);
        index++;
    }

    frame->addChild(scrollView);
}

void RightFrame::addRow(int index, Hero *hero)
{
    float y = -index * SCROLL_VIEW_INNER_HEIGHT + scrollViewHeight - SCROLL_VIEW_MARGIN;

    auto sprite = Sprite::create("img/battle-heroes-row-background.png");
    sprite->setAnchorPoint(Point(0, 1));

    auto portrait = new Sprite;
    portrait->initWithSpriteFrameName("portraits/" + hero->getSlug() + ".png");
    portrait->setAnchorPoint(Point(0, 0));
    portrait->setPosition(Point(SCROLL_VIEW_MARGIN * 2, SCROLL_VIEW_MARGIN * 2));
    sprite->addChild(portrait);

    auto name = fontCreator->titleLabel(hero->getName());
    name->setAnchorPoint(Point(0, 0));
    name->setPosition(ROW_1, 150);
    sprite->addChild(name);

    std::string damageText = "Damage: " + to_string(hero->getDamage());
    auto damageLabel = fontCreator->infoLabel(damageText);
    damageLabel->setAnchorPoint(Point(0, 0));
    damageLabel->setPosition(ROW_1, 100);
    sprite->addChild(damageLabel);

    std::string healthText = "Health: " + to_string(hero->getHealth());
    auto healthLabel = fontCreator->infoLabel(healthText);
    healthLabel->setAnchorPoint(Point(0, 0));
    healthLabel->setPosition(ROW_1, 60);
    sprite->addChild(healthLabel);

    std::string rangedText = "Ranged: " + to_string(hero->getRanged());
    auto rangedLabel = fontCreator->infoLabel(rangedText);
    rangedLabel->setAnchorPoint(Point(0, 0));
    rangedLabel->setPosition(ROW_2, 100);
    sprite->addChild(rangedLabel);

    std::string moveText = "Movement: " + to_string(hero->getMovement());
    auto moveLabel = fontCreator->infoLabel(moveText);
    moveLabel->setAnchorPoint(Point(0, 0));
    moveLabel->setPosition(ROW_2, 60);
    sprite->addChild(moveLabel);

    auto actionButton = getActionButton(hero);
    actionButton->setAnchorPoint(Point(0, 0));
    actionButton->setPosition(Point(ROW_3, 60));
    sprite->addChild(actionButton);

    sprite->setPositionY(y);

    scrollView->addChild(sprite);
}

ui::Button *RightFrame::getActionButton(Hero *hero)
{
    auto button = ui::Button::create("ui/action-button.png", "", "");

    // Translator: translator->tr("menu_" + key)
    auto label = fontCreator->buttonLabel("Use", "fonts/buttons-label.otf", 50);
    button->setTitleLabel(label);
    button->addTouchEventListener(
        [&](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
//                SoundPlayer::playEffect("sounds/button.mp3");
//                auto scene = BattleScene::createScene();
//                Director::getInstance()->replaceScene(TransitionFade::create(SCENES_TRANSITION_TIME, scene));
            }
        });

    return button;
}
