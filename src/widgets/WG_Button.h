//
// Created by Ben Beshara on 4/4/2022.
//

#ifndef RLG_CMAKE_WG_BUTTON_H
#define RLG_CMAKE_WG_BUTTON_H

#include <string>
#include "../core/widget.h"

typedef struct WGConfig_Button {
  // Dimensions
  int x = 0;
  int y = 0;
  int width = 128;
  int height = 32;
  
  // Appearance
  Font font;
  bool hasFont = false;
  int fontSize = 12;
  float fontSpacing = 0.5f;
  bool wordWrap = false;
  Color colour = BLACK;
  Color selectColour = WHITE;
  Color textColour = BLUE;
  
  // Functionality
  int selectBegin = 0;
  int selectLength = 0;
  std::string label;
  bool isFocused = false;
  
  std::string scriptFunction;
  
} WGConfig_Button;

class WG_Button : public Widget {
public:
  explicit WG_Button(WGConfig_Button *config);
  
  void Draw() override;
  
  void Step() override;
  
  Rectangle GetDimensions() override;
  
  RESIZE SetDimensions(Rectangle) override;

protected:
  WGConfig_Button *config;
  
  void Click() override;
  
  Rectangle GetCorrectedDimensions() override;
};


#endif //RLG_CMAKE_WG_BUTTON_H
