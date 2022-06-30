#ifndef WIDGET_H
#define WIDGET_H

#include "raylib.h"
#include <unordered_map>

enum RESIZE {
  CANNOT_RESIZE, RESIZED
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
  
  // Implementation-specific functions
  virtual void Draw() {};
  
  virtual void Step() {};
  
  virtual Rectangle GetDimensions() { return {0, 0, 0, 0}; };
  
  virtual RESIZE SetDimensions(Rectangle) { return CANNOT_RESIZE; };
  
  [[nodiscard]] float GetPointScale() const;
  
  void SetPointScale(float pointScale);
  
  [[nodiscard]] Vector2 GetGuiScale() const { return guiScale; };
  
  void SetGuiScale(Vector2 scale) { guiScale = scale; };
  
  Vector2 ContainerOffset = {0, 0};
  
  virtual void Click() {};

protected:
  bool focused{};
  
  bool hidden{};
  
  float pointScale = 1.0f;
  
  Vector2 guiScale = {1.0f, 1.0f};
};

#endif /* WIDGET_H */
