#ifndef STATE_H
#define STATE_H

#include "widget.h"
#include <iterator>
#include <unordered_map>
#include <vector>

class State {
protected:
    uint64_t widgetCount = 0;

public:
  uint64_t AddWidget(Widget *);
  void KillWidget(uint64_t);
  void BlurAllWidgets();
  void GameLoop();

  typedef std::unordered_map<uint64_t, Widget *>::iterator iterator;
  typedef std::unordered_map<uint64_t, Widget *>::const_iterator const_iterator;
  iterator begin() { return widgetList.begin(); }
  iterator end() { return widgetList.end(); }

    std::unordered_map<uint64_t, Widget *> widgetList;
};
#endif /* STATE_H */
