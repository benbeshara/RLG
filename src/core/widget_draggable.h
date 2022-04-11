#ifndef WIDGET_DRAGABLE_H
#define WIDGET_DRAGABLE_H

#include "widget.h"

typedef struct DragOffset {
  int x = 0;
  int y = 0;
} DragOffset;

class Widget_Draggable : public Widget {
public:
  void Draw() override {};
  
  void Step() override {};
  
  Rectangle GetDimensions() override { return {0, 0, 0, 0}; };
  
  RESIZE SetDimensions(Rectangle) override { return CANNOT_RESIZE; };

protected:
  void detect_drag();
  
  void drag();
  
  bool is_dragging{};
  DragOffset delta;
};

#endif /* WIDGET_DRAGABLE_H */