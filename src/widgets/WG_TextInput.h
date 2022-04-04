#ifndef WG_TEXTINPUT_H
#define WG_TEXTINPUT_H

#include "../core/widget.h"
#include "raylib.hpp"
#include <string>

typedef struct WGConfig_TextInput {
  // Dimensions
  int x = 0;
  int y = 0;
  int width = 128;
  int height = 32;
  
  // Appearance
  Font font = GetFontDefault();
  int fontSize = 12;
  float fontSpacing = 0.5f;
  bool wordWrap = false;
  Color colour = BLACK;
  Color selectColour = WHITE;
  Color selectBackColour = BLUE;
  
  // Functionality
  int selectBegin = 0;
  int selectLength = 0;
  std::string text = "";
  bool isFocused = false;
} WGConfig_TextInput;

class WG_TextInput : public Widget {
public:
  WG_TextInput(WGConfig_TextInput *);
  
  void Draw() override;
  
  void Step() override;
  
  Rectangle GetDimensions() override;
  
  RESIZE SetDimensions(Rectangle) override;
  
  std::string GetText();
  
  void SetText(std::string);

protected:
  WGConfig_TextInput *config;
};

#endif /* WG_TEXTINPUT_H */