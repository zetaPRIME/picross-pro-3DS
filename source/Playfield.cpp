#include "Playfield.h"

#include <cmath>
#include <algorithm>

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

constexpr int width = 20;
constexpr int height = 15;
constexpr Vector2 cell = Vector2(12, 12);

using std::floor;
using std::ceil;
using std::min;
using std::max;
using std::abs;
namespace {
    int clamp(int in, int mn, int mx) {
        return min(max(in, mn), mx);
    }
}

Playfield::Playfield(VRect rect) {
    this->rect = rect;
    field = std::vector<std::vector<char>>(width, std::vector<char>(height, 0));
}

void Playfield::Draw() {
    static auto square = ThemeManager::GetAsset("app:/grid.12.cell");
    static auto cursor = ThemeManager::GetAsset("app:/grid.12.cursor");
    static auto tick = ThemeManager::GetAsset("app:/grid.12.tick");
    static auto cross = ThemeManager::GetAsset("app:/grid.12.cross");
    Vector2 off = rect.pos + GFXManager::GetOffset();
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Vector2 pos = off + (Vector2(x,y) * cell);
            square->Draw(pos - Vector2::one);
            if (field[x][y] == 1) tick->Draw(pos);
            else if (field[x][y] == 2) cross->Draw(pos);
            
            if (x == lsx && y == lsy) cursor->Draw(pos);
        }
    }
}

void Playfield::OnTouchOn() {
    if (InputManager::Pressed(Keys::Touch)) {
        //MarkForRedraw();
        Vector2 rel = InputManager::TouchPos() - ScreenRect().pos;
        int tx = clamp(floor(rel.x / cell.x), 0, width-1);
        int ty = clamp(floor(rel.y / cell.y), 0, height-1);
        DrawSpace(tx, ty, true);
        
        tlx = tx; tly = ty;
        tsx = tx; tsy = ty;
        
        InputManager::GetDragHandle().Grab(this);
    }
}

void Playfield::OnDragHold() {
    Vector2 rel = InputManager::TouchPos() - ScreenRect().pos;
    int tx = clamp(floor(rel.x / cell.x), 0, width-1);
    int ty = clamp(floor(rel.y / cell.y), 0, height-1);
    
    int diff = min(abs(tx - tsx), abs(ty - tsy)); // minimum-axis difference between current cursor and where last slow draw was registered
    
    if (diff > 1 || InputManager::TouchDelta().Length() > 2) { // fast or disconnected, draw in a straight line
        if (tx != tlx || ty != tly) { // only process as moving if you've actually moved
            Vector2 cdl = Vector2(tx - tsx, ty - tsy).CardinalAxis(); // cardinal axis of movement
            if (cdl.x != 0) {
                tsx = -999; // lock to axis until slowed
                int x1 = min(tx, tlx);
                int x2 = max(tx, tlx);
                for (int ix = x1; ix <= x2; ix++) DrawSpace(ix, tsy);
                DrawSpace(tx, tsy); // re-set cursor
            }
            else {
                tsy = -999; // lock to axis until slowed
                int y1 = min(ty, tly);
                int y2 = max(ty, tly);
                for (int iy = y1; iy <= y2; iy++) DrawSpace(tsx, iy);
                DrawSpace(tsx, ty); // re-set cursor
            }
        }
    } else { // slow, draw wherever
        tsx = tx; tsy = ty;
        DrawSpace(tx, ty);
    }
    //
    
    tlx = tx; tly = ty;
    
}

void Playfield::OnDragRelease() {
    lsx = lsy = -1;
}

void Playfield::DrawSpace(int x, int y, bool initial) {
    lsx = x; lsy = y;
    char prv = field[x][y];
    if (initial) {
        Vector2 stick = (InputManager::CirclePad() + InputManager::CStick()).ClampLength();
        if (stick.y < -.8) tset = 1;
        else if (stick.y > .8) tset = 2;
        else tset = 255;
        
        //if (prv == tset) tset = 0;
        if (prv != 0) tset = 0;
        tconv = prv;
    }
    if (tset != 255 && (prv == tconv || tset == 0)) { // if stick not in neutral, and either started on a blank or setting blank
        field[x][y] = tset;
    }
}
