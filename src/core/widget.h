#ifndef WIDGET_H
#define WIDGET_H

#include "raylib.h"
#include <unordered_map>

enum RESIZE {
  CANNOT_RESIZE, RESIZED
};

enum SCALE_DIMENSIONS {
  X,
  Y,
  POINT
};

class Widget {
public:
  // Generic functions
  [[nodiscard]] bool isFocused() const;
  
  void Focus();
  
  void Blur();
  
  void Toggle();
  
  void Hide();
  
  void Show();
  
  void FocusCheck();
  
  void DebugDraw();
  
  // Implementation-specific functions
  virtual void Draw() {};
  
  virtual void Step() {};
  
  virtual Rectangle GetDimensions() { return {0, 0, 0, 0}; };
  
  virtual RESIZE SetDimensions(Rectangle) { return CANNOT_RESIZE; };
  
  virtual Rectangle GetCorrectedDimensions() { return GetDimensions(); };
  
  Vector2 ContainerOffset = {0, 0};
  
  [[nodiscard]] float GetCorrectedDimension(float base, SCALE_DIMENSIONS dimension) const;
  
  virtual void Click() {};

protected:
  bool focused{};
  
  bool hidden{};
};

#endif /* WIDGET_H */
