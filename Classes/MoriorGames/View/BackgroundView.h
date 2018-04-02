#ifndef MORIOR_GAMES_VIEW_BACKGROUND_VIEW_H
#define MORIOR_GAMES_VIEW_BACKGROUND_VIEW_H

#include "ViewHelper.h"

class BackgroundView: public ViewHelper
{
public:
    static const std::string NAME;

public:
    explicit BackgroundView(Layer *layer);

private:
    void addView() override;
};

#endif
