#ifndef WIDGET_CONTAINER_DRAGGABLE_H
#define WIDGET_CONTAINER_DRAGGABLE_H

#include "state.h"
#include "widget_draggable.h"

class Widget_Container_Draggable : public Widget_Draggable {
public:
  RESIZE SetContainerContentsDimensions();
  
  uint64_t AddWidget(Widget *widget);
  
  void DrawWidgets();
  
  void Draw() override {};
  
  void Step() override {};
  
  Rectangle GetDimensions() override { return {0, 0, 0, 0}; };
  
  RESIZE SetDimensions(Rectangle) override { return CANNOT_RESIZE; };
  
  State containerState;
};

#endif /* WIDGET_CONTAINER_DRAGGABLE_H */
