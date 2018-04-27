#include "FontCreator.h"

Label *FontCreator::buttonLabel(std::string text, std::string font, float size)
{
    auto label = Label::createWithTTF(text, font, size);
    label->enableOutline(STROKE_COLOR, 2);
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
