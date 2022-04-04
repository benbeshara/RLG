#include "WG_TextInput.h"
#include "raylib.hpp"
#include <string>

WG_TextInput::WG_TextInput(WGConfig_TextInput *config) {
  this->config = config;
}

Rectangle WG_TextInput::GetDimensions() {
  WGConfig_TextInput *config = this->config;
  return {(float)config->x, (float)config->y, (float)config->width,
          (float)config->height};
}

RESIZE WG_TextInput::SetDimensions(Rectangle newDimensions) {
  this->config->x = newDimensions.x;
  this->config->y = newDimensions.y;
  this->config->width = newDimensions.width;
  this->config->height = newDimensions.height;

  return RESIZED;
}

void WG_TextInput::Draw() {
  WGConfig_TextInput *config = this->config;
  DrawTextRecEx(GetFontDefault(), config->text.c_str(), this->GetDimensions(),
                config->fontSize, config->fontSpacing, config->wordWrap,
                config->colour, config->selectBegin, config->selectLength,
                config->selectColour, config->selectBackColour);
}

void WG_TextInput::Step() {
  if (focused) {
    int key = GetCharPressed();
    if (key > 0)
      this->config->text.append(1, key);
  }
}

std::string WG_TextInput::GetText() { return this->config->text; }

void WG_TextInput::SetText(std::string text) { this->config->text = text; }