#ifndef WIDGET_DRAGABLE_H
#define WIDGET_DRAGABLE_H

#include "widget.h"

typedef struct DragOffset {
  int x = 0;
  int y = 0;
} DragOffset;

class Widget_Draggable : public Widget {
public:
  virtual void Draw() {};
  
  virtual void Step() {};
  
  virtual Rectangle GetDimensions() { return {0, 0, 0, 0}; };
  
  virtual RESIZE SetDimensions(Rectangle) { return CANNOT_RESIZE; };

protected:
  void detect_drag();
  
  void drag();
  
  bool is_dragging;
  DragOffset delta;
};

#endif /* WIDGET_DRAGABLE_H */