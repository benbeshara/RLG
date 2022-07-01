#include "widget_container_draggable.h"

uint64_t Widget_Container_Draggable::AddWidget(Widget *widget, const std::optional<std::string> &widgetName,
                                               std::optional<uint64_t> parentId) {
  widget->ContainerOffset = {widget->GetCorrectedDimensions().x,
                             widget->GetCorrectedDimensions().y};
  return containerState.AddWidget(widget, widgetName, parentId);
}

void Widget_Container_Draggable::DrawWidgets() {
  SetContainerContentsDimensions();
  
  containerState.GameLoop();
}

RESIZE Widget_Container_Draggable::SetContainerContentsDimensions() {
  State::iterator i;
  
  Rectangle ContainerDimensionsThisFrame = GetDimensions();
  
  for (auto &value: containerState) {
    Rectangle WidgetDimensionsThisFrame = value.second->GetDimensions();
    Vector2 WidgetContainerOffset = value.second->ContainerOffset;
    
    value.second->SetDimensions(
        {WidgetContainerOffset.x + ContainerDimensionsThisFrame.x,
         WidgetContainerOffset.y + ContainerDimensionsThisFrame.y,
         WidgetDimensionsThisFrame.width, WidgetDimensionsThisFrame.height});
  }
  
  return RESIZE::RESIZED;
}