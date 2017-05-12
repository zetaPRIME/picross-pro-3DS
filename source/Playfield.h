#pragma once

#include <vector>

#include "starlight/ui/UIElement.h"

namespace picrosspro {
    class Playfield : public sl::ui::UIElement {
    private:
        int tsx = 0;
        int tsy = 0;
        int tlx = 0;
        int tly = 0;
        char tset = 0;
        char tconv = 0;
        
        // last set
        int lsx = -1;
        int lsy = -1;
        
        void DrawSpace(int x, int y, bool initial = false);
    public:
        std::vector<std::vector<char>> field;
        
        Playfield(sl::VRect rect);
        Playfield(sl::Vector2 pos) : Playfield(sl::VRect(pos, sl::Vector2(20*12, 15*12))) { }
        ~Playfield() { }
        
        void Draw() override;
        
        // events
        void OnTouchOn() override;
        //void OnTouchOff() override;
        
        //void OnDragStart() override;
        void OnDragRelease() override;
        void OnDragHold() override;
        
    };
}
