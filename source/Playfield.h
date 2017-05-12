#pragma once

#include "starlight/ui/UIElement.h"

namespace picrosspro {
    class Playfield : public sl::ui::UIElement {
    public:
        Playfield(sl::VRect rect) { this->rect = rect; }
        Playfield(sl::Vector2 pos) { this->rect = sl::VRect(pos, sl::Vector2(15*12, 15*12)); }
        ~Playfield() { }
        
        void Draw() override;
        
        // events
        //void OnTouchOn() override;
        //void OnTouchOff() override;
        
        //void OnDragStart() override;
        //void OnDragRelease() override;
        //void OnDragHold() override;
        
    };
}
