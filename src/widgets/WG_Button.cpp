//
// Created by Ben Beshara on 4/4/2022.
//

#include "WG_Button.h"
#include "../core/GameStore.h"

void WG_Button::Click() {
  GameStore *store = GameStore::GetInstance();
  
  if (!this->config->scriptFunction.empty()) {
    store->getScript()->runOnce(this->config->scriptFunction);
  }
}

WG_Button::WG_Button(WGConfig_Button *config) {
  this->config = config;
}

void WG_Button::Draw() {
  if (this->hidden) return;
  
  Color buttonColour;
  if (this->focused) {
    buttonColour = this->config->selectColour;
  } else {
    buttonColour = this->config->colour;
  }
  
  DrawRectangle(
      GetCorrectedDimension(this->config->x, X),
      GetCorrectedDimension(this->config->y, Y),
      GetCorrectedDimension(this->config->width, X),
      GetCorrectedDimension(this->config->height, Y),
      buttonColour
  );
  DrawTextEx(
      this->config->font,
      this->config->label.c_str(),
      {
          (float) GetCorrectedDimension(this->config->x, X),
          (float) GetCorrectedDimension(this->config->y, Y)
      },
      GetCorrectedDimension(12, POINT),
      1,
      this->config->textColour);
}

void WG_Button::Step() {
  Widget::Step();
}

Rectangle WG_Button::GetDimensions() {
  return {(float) this->config->x, (float) this->config->y, (float) this->config->width, (float) this->config->height};
}

Rectangle WG_Button::GetCorrectedDimensions() {
  return {
      GetCorrectedDimension(this->config->x, X),
      GetCorrectedDimension(this->config->y, Y),
      GetCorrectedDimension(this->config->width, X),
      GetCorrectedDimension(this->config->height, Y),
  };
}

RESIZE WG_Button::SetDimensions(Rectangle dimensions) {
  return Widget::SetDimensions(dimensions);
}
