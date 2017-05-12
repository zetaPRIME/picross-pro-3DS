#pragma once

#include "starlight/Application.h"

namespace picrosspro {
    class Game : public sl::Application {
    public:
        Game() : Application("picross-pro") { }
        ~Game() override = default;
        
        void Init() override;
        void End() override;
        void Update() override;
        
    };
}
