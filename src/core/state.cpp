#include <string>
#include "state.h"

/**
 * Add a widget to the state machine
 * Returns index of widget at end of stack
 **/
uint64_t State::AddWidget(Widget *widget, const std::optional<std::string> &widgetName) {
  this->widgetList.emplace(this->widgetCount, widget);
  this->widgetCount++;
  
  if (widgetName && *widgetName != "") {
    this->namedWidgets.emplace(*widgetName, this->widgetCount - 1);
  }
  
  return this->widgetCount - 1;
}

uint64_t State::GetWidgetIDByName(std::string widgetName) {
  return this->namedWidgets.find(widgetName)->second;
}

/**
 * Removes a widget from the state machine
 **/
void State::KillWidget(uint64_t key) { this->widgetList.erase(key); }

void State::BlurAllWidgets() {
  for (auto &value: this->widgetList) {
    value.second->Blur();
  }
}

void State::GameLoop() {
  for (auto &value: this->widgetList) {
    value.second->FocusCheck();
    value.second->Draw();
    value.second->Step();
  }
}