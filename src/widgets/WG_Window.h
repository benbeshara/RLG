#ifndef WG_WINDOW_H
#define WG_WINDOW_H

#include "../core/widget_container_draggable.h"

typedef struct WGConfig_Window {
  // Dimensions
  int x = 0;
  int y = 0;
  int width = 256;
  int height = 196;
  Color colour = BLUE;
  std::optional<Color> focusedColour = std::nullopt;
  
  bool isFocused = false;
} WGConfig_Window;

class WG_Window : public Widget_Container_Draggable {
public:
  explicit WG_Window(WGConfig_Window *);
  
  void Draw() override;
  
  void Step() override;
  
  Rectangle GetDimensions() override;
  
  RESIZE SetDimensions(Rectangle) override;

protected:
  WGConfig_Window *config;
};

#endif /* WG_WINDOW_H */
