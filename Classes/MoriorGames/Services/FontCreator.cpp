#include "FontCreator.h"

Label *FontCreator::buttonLabel(std::string text, std::string font, float size)
{
    auto label = Label::createWithTTF(text, font, size);
    label->enableOutline(STROKE_COLOR, 2);
    label->enableShadow();

    return label;
}
