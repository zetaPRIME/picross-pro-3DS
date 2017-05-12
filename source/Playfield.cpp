#include "Playfield.h"

#include <cmath>

#include "starlight/ThemeManager.h"
#include "starlight/GFXManager.h"
#include "starlight/InputManager.h"

using sl::Vector2;
using sl::VRect;
using sl::Color;

using sl::ThemeManager;
using sl::GFXManager;
using sl::InputManager;

using namespace picrosspro;

constexpr int width = 15;
constexpr int height = 15;
constexpr Vector2 cell = Vector2(12, 12);

Playfield::Playfield(VRect rect) {
    this->rect = rect;
    field = std::vector<std::vector<int>>(width, std::vector<int>(height, 1));
}

void Playfield::Draw() {
    static auto tick = ThemeManager::GetAsset("app:/grid.tick");
    Vector2 off = rect.pos + GFXManager::GetOffset();
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Vector2 pos = off + (Vector2(x,y) * cell);
            if (field[x][y] > 0) tick->Draw(pos);
        }
    }
}

void Playfield::OnTouchOn() {
    if (InputManager::Pressed(Keys::Touch)) {
        //InputManager::GetDragHandle().Grab(this);
        //MarkForRedraw();
        Vector2 rel = InputManager::TouchPos() - ScreenRect().pos;
        int tx = std::floor(rel.x / cell.x);
        int ty = std::floor(rel.y / cell.y);
        field[tx][ty] *= -1;
    }
}
