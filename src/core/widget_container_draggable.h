#ifndef WIDGET_CONTAINER_DRAGGABLE_H
#define WIDGET_CONTAINER_DRAGGABLE_H
#include "state.h"
#include "widget_draggable.h"

class Widget_Container_Draggable : public Widget_Draggable {
public:
  RESIZE SetContainerContentsDimensions();
  
  uint64_t AddWidget(Widget *widget);
  void DrawWidgets();
  virtual void Draw(){};
  virtual void Step(){};
  virtual Rectangle GetDimensions() { return {0, 0, 0, 0}; };
  virtual RESIZE SetDimensions(Rectangle) { return CANNOT_RESIZE; };

  State containerState;
};

#endif /* WIDGET_CONTAINER_DRAGGABLE_H */
