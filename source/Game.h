#pragma once

#include "starlight/Application.h"

using starlight::Application;

class Game : public Application {
public:
    Game() : Application("picross-pro") { }
    ~Game() override = default;
    
    void Init() override;
    void End() override;
    void Update() override;

};
