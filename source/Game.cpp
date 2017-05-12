#include "Game.h"

#include <3ds.h>

#include "starlight/InputManager.h"
#include "starlight/ConfigManager.h"
#include "starlight/ThemeManager.h"
#include "starlight/GFXManager.h"

#include "starlight/Application.h"

#include "starlight/util/Path.h"

using starlight::Vector2;
using starlight::VRect;
using starlight::Color;
using starlight::InputManager;
using starlight::ConfigManager;
using starlight::ThemeManager;
using starlight::GFXManager;

using starlight::util::Path;

using starlight::Application;

void Game::Init() {
    clearColor = Color(.5, .75, 1);
}

void Game::End() {
    
}

void Game::Update() {
    //if (InputManager::Held(Keys::Y) || InputManager::Pressed(Keys::Start)) Application::Quit();
}
