#include "FontCreator.h"

Label *FontCreator::buttonLabel(std::string text, std::string font, float size)
{
    auto label = Label::createWithTTF(text, font, size);
    label->enableOutline(Color4B::BLACK, 2);
    label->enableShadow();

    return label;
}

Label *FontCreator::damageLabel(std::string text, std::string font, float size)
{
    auto label = Label::createWithTTF(text, font, size);
    label->setColor(Color3B::WHITE);
    label->enableOutline(Color4B::RED, 4);
    label->enableShadow();

    return label;
}

Label *FontCreator::hitPointsLabel(std::string text, std::string font, float size)
{
    auto label = Label::createWithTTF(text, font, size);
    label->setColor(Color3B::WHITE);
    label->enableOutline(Color4B::BLACK, 2);
    label->enableShadow();

    return label;
}

Label *FontCreator::titleLabel(std::string text, std::string font, float size)
{
    auto label = Label::createWithTTF(text, font, size);
    label->setColor(Color3B::WHITE);
    label->enableOutline(Color4B::BLACK, 2);
    label->enableShadow();

    return label;
}

Label *FontCreator::infoLabel(std::string text, std::string font, float size)
{
    auto label = Label::createWithTTF(text, font, size);
    label->setColor(Color3B::WHITE);

    return label;
}
