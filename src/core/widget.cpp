#include "widget.h"
#include "raylib.h"

bool Widget::isFocused() const { return this->focused; }

void Widget::Focus() { this->focused = true; }

void Widget::Blur() { this->focused = false; }

void Widget::Toggle() { this->hidden = !this->hidden; }

void Widget::Hide() { this->hidden = true; }

void Widget::Show() { this->hidden = false; }

float Widget::GetPointScale() const { return this->pointScale; }

void Widget::SetPointScale(float scale) { this->pointScale = scale; }

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
