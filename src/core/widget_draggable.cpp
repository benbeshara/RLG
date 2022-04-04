#include "widget_draggable.h"
#include "raylib.hpp"
#include <string>

void Widget_Draggable::detect_drag() {
  // Are we holding the cutton down in the right spot? Are we focused?
  if (CheckCollisionPointRec(GetMousePosition(), this->GetDimensions()) &&
      IsMouseButtonDown(MOUSE_LEFT_BUTTON) && this->focused) {
    this->delta.x = GetMousePosition().x - this->GetDimensions().x;
    this->delta.y = GetMousePosition().y - this->GetDimensions().y;
    this->is_dragging = true;
  } else {
    this->is_dragging = false;
  }
}

void Widget_Draggable::drag() {
  // If we're not dragging ths tick, detect it
  // and set us up for the next one
  if (this->is_dragging == false) {
    this->detect_drag();
    return;
  }

  Rectangle oldDimensions = this->GetDimensions();
  Rectangle draggedDimensions = {GetMousePosition().x - this->delta.x,
                                 GetMousePosition().y - this->delta.y,
                                 oldDimensions.width, oldDimensions.height};
  this->SetDimensions(draggedDimensions);

  // See if we've stopped dragging
  this->detect_drag();
}