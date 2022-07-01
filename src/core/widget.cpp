#include "widget.h"
#include "raylib.h"
#include "GameStore.h"

bool Widget::isFocused() const { return this->focused; }

void Widget::Focus() { this->focused = true; }

void Widget::Blur() { this->focused = false; }

void Widget::Toggle() { this->hidden = !this->hidden; }

void Widget::Hide() { this->hidden = true; }

void Widget::Show() { this->hidden = false; }

void Widget::FocusCheck() {
  if (!this->focused &&
      CheckCollisionPointRec(GetMousePosition(), this->GetCorrectedDimensions()) &&
      IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
    focused = true;
    return;
  }
  if (this->focused &&
      !CheckCollisionPointRec(GetMousePosition(), this->GetCorrectedDimensions()) &&
      IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
    focused = false;
    return;
  }
  if (this->focused &&
      CheckCollisionPointRec(GetMousePosition(), this->GetCorrectedDimensions()) &&
      IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
    this->Click();
    return;
  }
}

int snap(float num) {
  GameStore *store = GameStore::GetInstance();
  int snapSize = store->getConfig()->getConfig<int>(gameConfig::SNAPSIZE);
  return snapSize * round(num / snapSize);
}

float Widget::GetCorrectedDimension(float base, SCALE_DIMENSIONS dimension) const {
  GameStore *store = GameStore::GetInstance();
  
  switch (dimension) {
    case SCALE_DIMENSIONS::X:
      return snap(base) * store->getState()->GetGuiScale().x;
    case SCALE_DIMENSIONS::Y:
    case SCALE_DIMENSIONS::POINT:
      return snap(base) * store->getState()->GetGuiScale().y;
    default:
      return base;
  }
}

void Widget::DebugDraw() {
  GameStore *store = GameStore::GetInstance();
  if (store->getConfig()->getConfig<int>(gameConfig::DEBUG_DRAW) > 0) {
    DrawRectangleLinesEx(this->GetCorrectedDimensions(), 2,
                         PURPLE);
  }
}