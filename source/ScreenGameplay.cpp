#include "ScreenGameplay.h"

#include "starlight/ui/Button.h"

#include "Playfield.h"

using starlight::Vector2;
using starlight::VRect;
using starlight::Color;

using namespace picrosspro;

ScreenGameplay::ScreenGameplay() : sl::ui::Form(true) {
    //
    //touchScreen->AddNew<sl::ui::Button>(VRect(16, 16, 64, 32));
    touchScreen->AddNew<Playfield>(Vector2(48, 48));
}
