#ifndef STATE_H
#define STATE_H

#include "widget.h"
#include <iterator>
#include <unordered_map>
#include <vector>
#include <string>

class State {
protected:
  uint64_t widgetCount = 0;
  Vector2 guiScale = {1.0f, 1.0f};

public:
  uint64_t AddWidget(Widget *, const std::optional<std::string> &widgetName = std::nullopt,
                     std::optional<uint64_t> parentId = -1);
  
  Widget *getWidget(uint64_t widgetId);
  
  void KillWidget(uint64_t);
  
  void BlurAllWidgets();
  
  Vector2 GetGuiScale() { return guiScale; };
  
  void SetGuiScale(Vector2 scale) { guiScale = scale; };
  
  void GameLoop();
  
  typedef std::unordered_map<uint64_t, Widget *>::iterator iterator;
  typedef std::unordered_map<uint64_t, Widget *>::const_iterator const_iterator;
  
  typedef std::unordered_map<std::string, std::pair<uint64_t, uint64_t>>::iterator namediterator;
  typedef std::unordered_map<std::string, std::pair<uint64_t, uint64_t>>::const_iterator const_namediterator;
  
  iterator begin() { return widgetList.begin(); }
  
  iterator end() { return widgetList.end(); }
  
  namediterator beginNamed() { return namedWidgets.begin(); }
  
  namediterator endNamed() { return namedWidgets.end(); }
  
  std::unordered_map<uint64_t, Widget *> widgetList;
  std::unordered_map<std::string, std::pair<uint64_t, uint64_t>> namedWidgets;
  
  std::pair<uint64_t, uint64_t> GetWidgetIDByName(const std::string &name);
  
  Widget *GetWidgetByName(const std::string &widgetName);
};

#endif /* STATE_H */
