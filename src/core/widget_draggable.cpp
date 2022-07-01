#include "widget_draggable.h"
#include "raylib.h"
#include "GameStore.h"
#include <string>

void Widget_Draggable::detect_drag() {
  // Are we holding the button down in the right spot? Are we focused?
  if ((CheckCollisionPointRec(GetMousePosition(), this->GetCorrectedDimensions()) &&
       IsMouseButtonDown(MOUSE_LEFT_BUTTON) && this->focused) ||
      (this->is_dragging && IsMouseButtonDown(MOUSE_LEFT_BUTTON))) {
    this->delta.x = static_cast<int>(GetMousePosition().x - this->GetCorrectedDimensions().x);
    this->delta.y = static_cast<int>(GetMousePosition().y - this->GetCorrectedDimensions().y);
    this->is_dragging = true;
  } else {
    this->is_dragging = false;
  }
}

void Widget_Draggable::drag() {
  // If we're not dragging ths tick, detect it
  // and set us up for the next one
  if (!this->is_dragging) {
    this->detect_drag();
    return;
  }
  
  GameStore *store = GameStore::GetInstance();
  
  Rectangle oldDimensions = this->GetDimensions();
  Rectangle draggedDimensions = {
      (GetMousePosition().x - static_cast<float>(this->delta.x)) / store->getState()->GetGuiScale().x,
      (GetMousePosition().y - static_cast<float>(this->delta.y)) / store->getState()->GetGuiScale().y,
      oldDimensions.width, oldDimensions.height};
  this->SetDimensions(draggedDimensions);
  
  // See if we've stopped dragging
  this->detect_drag();
}
