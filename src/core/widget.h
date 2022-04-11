#ifndef WIDGET_H
#define WIDGET_H

#include "raylib.hpp"
#include <unordered_map>

enum RESIZE {
  CANNOT_RESIZE, RESIZED
};

class Widget {
public:
  // Generic functions
  bool isFocused();
  
  void Focus();
  
  void Blur();
  
  void Toggle();
  
  void Hide();
  
  void Show();
  
  void FocusCheck();
  
  // Implementation-specific functions
  virtual void Draw() {};
  
  virtual void Step() {};
  
  virtual Rectangle GetDimensions() { return {0, 0, 0, 0}; };
  
  virtual RESIZE SetDimensions(Rectangle) { return CANNOT_RESIZE; };
  
  Vector2 ContainerOffset = {0, 0};
  
  virtual void Click() {};

protected:
  bool focused;
  bool hidden;
};

#endif /* WIDGET_H */
