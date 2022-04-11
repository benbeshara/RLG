#include "widget.h"
#include "raylib.hpp"

bool Widget::isFocused() { return this->focused; };

void Widget::Focus() { this->focused = true; };

void Widget::Blur() { this->focused = false; };

void Widget::Toggle() { this->hidden = !this->hidden; }

void Widget::Hide() { this->hidden = true; }

void Widget::Show() { this->hidden = false; }

void Widget::FocusCheck() {
  if (!this->focused &&
      CheckCollisionPointRec(GetMousePosition(), this->GetDimensions()) &&
      IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
    focused = true;
    return;
  }
  if (this->focused &&
      !CheckCollisionPointRec(GetMousePosition(), this->GetDimensions()) &&
      IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
    focused = false;
    return;
  }
  if (this->focused &&
      CheckCollisionPointRec(GetMousePosition(), this->GetDimensions()) &&
      IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
    this->Click();
    return;
  }
}
