#include "Game.h"

#include <3ds.h>

#include "starlight/InputManager.h"
#include "starlight/ConfigManager.h"
#include "starlight/ThemeManager.h"
#include "starlight/GFXManager.h"

#include "starlight/Application.h"

#include "starlight/util/Path.h"

#include "ScreenGameplay.h"

using starlight::Vector2;
using starlight::VRect;
using starlight::Color;
using starlight::InputManager;
using starlight::ConfigManager;
using starlight::ThemeManager;
using starlight::GFXManager;

using starlight::util::Path;

using starlight::Application;

using namespace picrosspro;

void Game::Init() {
    //clearColor = Color(.5, .75, 1);
    ScreenGameplay::New()->Open();
}

void Game::End() {
    
}

void Game::Update() {
    //if (InputManager::Pressed(Keys::A)) clearColor = Color(.5, 1, .5);
}
