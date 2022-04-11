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
  GameStore *store = GameStore::GetInstance();
  this->config = config;
  store->getScript()->ctx.add(chaiscript::fun(&WG_Button::doButtonClick, this), "doButtonClick");
}

void WG_Button::doButtonClick(std::string widget) {
  GameStore *store = GameStore::GetInstance();
  const auto key = store->getState()->GetWidgetIDByName(widget);
  store->getState()->KillWidget(key);
  TraceLog(LOG_INFO, "Clicked!");
}

void WG_Button::Draw() {
  Color buttonColour;
  if (this->focused) {
    buttonColour = this->config->selectColour;
  } else {
    buttonColour = this->config->colour;
  }
  
  DrawRectangle(this->config->x, this->config->y, this->config->width, this->config->height, buttonColour);
  DrawTextEx(this->config->font, this->config->label.c_str(), {(float) this->config->x, (float) this->config->y}, 12, 1,
             this->config->textColour);
}

void WG_Button::Step() {
  Widget::Step();
}

Rectangle WG_Button::GetDimensions() {
  return {(float) this->config->x, (float) this->config->y, (float) this->config->width, (float) this->config->height};
}

RESIZE WG_Button::SetDimensions(Rectangle dimensions) {
  return Widget::SetDimensions(dimensions);
}
