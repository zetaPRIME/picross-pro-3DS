#pragma once

#include <vector>

#include "starlight/ui/UIElement.h"

namespace picrosspro {
    class Playfield : public sl::ui::UIElement {
    public:
        std::vector<std::vector<int>> field;
        
        Playfield(sl::VRect rect);
        Playfield(sl::Vector2 pos) : Playfield(sl::VRect(pos, sl::Vector2(15*12, 15*12))) { }
        ~Playfield() { }
        
        void Draw() override;
        
        // events
        void OnTouchOn() override;
        //void OnTouchOff() override;
        
        //void OnDragStart() override;
        //void OnDragRelease() override;
        //void OnDragHold() override;
        
    };
}
