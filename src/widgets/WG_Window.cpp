#include "./WG_Window.h"

WG_Window::WG_Window(WGConfig_Window *config) { this->config = config; }

void WG_Window::Draw() {
  DrawRectangle(this->config->x, this->config->y, this->config->width,
                this->config->height, this->config->colour);

  DrawWidgets();
}

void WG_Window::Step() {
  this->drag();
  this->FocusCheck();

  if (this->focused) {
    this->config->colour = RED;
  } else {
    this->config->colour = BLUE;
  }
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