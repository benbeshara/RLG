#include <string>
#include "state.h"
#include "widget_container_draggable.h"
#include "GameStore.h"

/**
 * Add a widget to the state machine
 * Returns index of widget at end of stack
 **/
uint64_t
State::AddWidget(Widget *widget, const std::optional<std::string> &widgetName, const std::optional<uint64_t> parentId) {
  this->widgetList.emplace(this->widgetCount, widget);
  this->widgetCount++;
  
  if (widgetName && !widgetName->empty()) {
    GameStore *store = GameStore::GetInstance();
    store->getState()->namedWidgets.emplace(*widgetName, std::make_pair(this->widgetCount - 1, *parentId));
  }
  
  return this->widgetCount - 1;
}

Widget *State::getWidget(uint64_t widgetId) {
  return this->widgetList.find(widgetId)->second;
}

std::pair<uint64_t, uint64_t> State::GetWidgetIDByName(const std::string &widgetName) {
  return this->namedWidgets.find(widgetName)->second;
}

Widget *State::GetWidgetByName(const std::string &widgetName) {
  auto match = this->GetWidgetIDByName(widgetName);
  if (match.second < 0)
    return getWidget(match.first);
  
  auto container = dynamic_cast<Widget_Container_Draggable *>(this->getWidget(match.second));
  return container->containerState.getWidget(match.first);
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