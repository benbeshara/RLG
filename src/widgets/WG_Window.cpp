#include "./WG_Window.h"

WG_Window::WG_Window(WGConfig_Window *config) { this->config = config; }

void WG_Window::Draw() {
    Color windowColour;
    if (this->focused && this->config->focusedColour) {
        windowColour = *this->config->focusedColour;
    } else {
        windowColour = this->config->colour;
    }
  DrawRectangle(this->config->x, this->config->y, this->config->width,
                this->config->height, windowColour);

  DrawWidgets();
}

void WG_Window::Step() {
  this->drag();
  this->FocusCheck();
}

Rectangle WG_Window::GetDimensions() {
  return {(float)this->config->x, (float)this->config->y,
          (float)this->config->width, (float)this->config->height};
}

RESIZE WG_Window::SetDimensions(Rectangle newDimensions) {
  this->config->x = newDimensions.x;
  this->config->y = newDimensions.y;
  this->config->width = newDimensions.width;
  this->config->height = newDimensions.height;

  this->SetContainerContentsDimensions();

  return RESIZED;
}