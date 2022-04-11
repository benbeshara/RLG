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

public:
  uint64_t AddWidget(Widget *, const std::optional<std::string> &widgetName = std::nullopt);
  
  void KillWidget(uint64_t);
  
  void BlurAllWidgets();
  
  void GameLoop();
  
  typedef std::unordered_map<uint64_t, Widget *>::iterator iterator;
  typedef std::unordered_map<uint64_t, Widget *>::const_iterator const_iterator;
  
  typedef std::unordered_map<std::string, uint64_t>::iterator namediterator;
  typedef std::unordered_map<std::string, uint64_t>::const_iterator const_namediterator;
  
  iterator begin() { return widgetList.begin(); }
  
  iterator end() { return widgetList.end(); }
  
  namediterator beginNamed() { return namedWidgets.begin(); }
  
  namediterator endNamed() { return namedWidgets.end(); }
  
  std::unordered_map<uint64_t, Widget *> widgetList;
  std::unordered_map<std::string, uint64_t> namedWidgets;
  
  uint64_t GetWidgetIDByName(std::string name);
};

#endif /* STATE_H */
