#ifndef MORIOR_GAMES_VIEW_BUTTONS_TRAINING_BUTTON_H
#define MORIOR_GAMES_VIEW_BUTTONS_TRAINING_BUTTON_H

#include "ui/CocosGUI.h"
#include "../ViewHelper.h"

class TrainingButton: public ViewHelper
{
public:
    float const BUTTON_X = -300;
    float const BUTTON_Y = -85;

    explicit TrainingButton(Layer *layer);

private:
    void addView() override;
};

#endif
