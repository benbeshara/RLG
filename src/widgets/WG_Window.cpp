#include "./WG_Window.h"

WG_Window::WG_Window(WGConfig_Window *config) { this->config = config; }

void WG_Window::Draw() {
  if (this->hidden) return;
  this->DebugDraw();
  Color windowColour;
  if (this->focused) {
    windowColour = *this->config->focusedColour;
  } else {
    windowColour = this->config->colour;
  }
  DrawRectangle(
      GetCorrectedDimension(this->config->x, X),
      GetCorrectedDimension(this->config->y, Y),
      GetCorrectedDimension(this->config->width, X),
      GetCorrectedDimension(this->config->height, Y),
      windowColour
  );
  
  DrawWidgets();
}

void WG_Window::Step() {
  this->drag();
  this->FocusCheck();
}

Rectangle WG_Window::GetDimensions() {
  return {
      (float) this->config->x,
      (float) this->config->y,
      (float) this->config->width,
      (float) this->config->height
  };
}

Rectangle WG_Window::GetCorrectedDimensions() {
  return {
      GetCorrectedDimension(this->config->x, X),
      GetCorrectedDimension(this->config->y, Y),
      GetCorrectedDimension(this->config->width, X),
      GetCorrectedDimension(this->config->height, Y),
  };
}

RESIZE WG_Window::SetDimensions(Rectangle newDimensions) {
  this->config->x = static_cast<int>(newDimensions.x);
  this->config->y = static_cast<int>(newDimensions.y);
  this->config->width = static_cast<int>(newDimensions.width);
  this->config->height = static_cast<int>(newDimensions.height);
  
  this->SetContainerContentsDimensions();
  
  return RESIZED;
}