#include "WG_TextInput.h"
#include "raylib.h"
#include <string>
#include <utility>

WG_TextInput::WG_TextInput(WGConfig_TextInput *config) {
  this->config = config;
}

Rectangle WG_TextInput::GetDimensions() {
  return {
      (float) this->config->x,
      (float) this->config->y,
      (float) this->config->width,
      (float) this->config->height
  };
}

Rectangle WG_TextInput::GetCorrectedDimensions() {
  return {
      GetCorrectedDimension(this->config->x, X),
      GetCorrectedDimension(this->config->y, Y),
      GetCorrectedDimension(this->config->width, X),
      GetCorrectedDimension(this->config->height, Y),
  };
}

RESIZE WG_TextInput::SetDimensions(Rectangle newDimensions) {
  this->config->x = static_cast<int>(newDimensions.x);
  this->config->y = static_cast<int>(newDimensions.y);
  this->config->width = static_cast<int>(newDimensions.width);
  this->config->height = static_cast<int>(newDimensions.height);
  
  return RESIZED;
}

void WG_TextInput::Draw() {
  if (this->hidden) return;
  this->DebugDraw();
//  Rectangle x = this->GetDimensions();
//  TraceLog(LOG_INFO, std::to_string(x.width).c_str());
//  DrawRectangleLinesEx(this->GetCorrectedDimensions(), 2, BLUE);
  DrawTextRecEx(GetFontDefault(),
                this->config->text.c_str(),
                this->GetCorrectedDimensions(),
                this->GetCorrectedDimension(this->config->fontSize, POINT),
                this->config->fontSpacing,
                this->config->wordWrap,
                this->config->colour,
                this->config->selectBegin,
                this->config->selectLength,
                this->config->selectColour,
                this->config->selectBackColour
  );
}

void WG_TextInput::Step() {
  if (focused) {
    if (GetKeyPressed() == KEY_BACKSPACE || GetKeyPressed() == KEY_DELETE) {
      this->config->text = this->config->text.substr(0, this->config->text.length() - 1);
    } else {
      int key = GetCharPressed();
      if (key > 0)
        this->config->text.append(1, key);
    }
  }
}

std::string WG_TextInput::GetText() { return this->config->text; }

void WG_TextInput::SetText(std::string text) { this->config->text = std::move(text); }