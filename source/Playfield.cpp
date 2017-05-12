#include "Playfield.h"

#include "starlight/ThemeManager.h"
#include "starlight/GFXManager.h"

using sl::Vector2;
using sl::VRect;
using sl::Color;

using sl::ThemeManager;
using sl::GFXManager;

using namespace picrosspro;

constexpr int width = 15;
constexpr int height = 15;

void Playfield::Draw() {
    static auto tick = ThemeManager::GetAsset("app:/grid.tick");
    Vector2 cell(12, 12);
    Vector2 off = rect.pos + GFXManager::GetOffset();
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Vector2 pos = off + (Vector2(x,y) * cell);
            tick->Draw(pos);
        }
    }
}
