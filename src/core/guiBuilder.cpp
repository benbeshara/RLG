//
// Created by Ben Beshara on 4/4/2022.
//

#include "guiBuilder.h"
#include "json.hpp"
#include "../widgets/WG_TextInput.h"
#include "../widgets/WG_Window.h"
#include "../widgets/WG_Button.h"
#include "GameStore.h"

enum ScaleDirection {
  x,
  y
};

static int getRelativeDimension(ScaleDirection dir, int src, int dest) {
  GameStore *store = GameStore::GetInstance();
  int windowSize;
  if (dir == x) {
    windowSize = store->getConfig()->getConfig<int>(gameConfig::E_CONFIG::SCREEN_SIZE_X);
  }
  if (dir == y) {
    windowSize = store->getConfig()->getConfig<int>(gameConfig::E_CONFIG::SCREEN_SIZE_Y);
  }
  return src * (windowSize / dest);
}

guiBuilder::guiBuilder(const std::string &widget, nlohmann::json props, Vector2 canvasSize) {
  if (canvasSize.x < 0 || canvasSize.y < 0) {
    GameStore *store = GameStore::GetInstance();
    
    canvasSize.x = store->getConfig()->getConfig<int>(gameConfig::E_CONFIG::SCREEN_SIZE_X);
    canvasSize.y = store->getConfig()->getConfig<int>(gameConfig::E_CONFIG::SCREEN_SIZE_Y);
  }
  if (widget == "WG_TextInput") {
    auto *config = new WGConfig_TextInput();
    
    config->text = props["text"];
    config->x = getRelativeDimension(x, props["x"], canvasSize.x);
    config->y = getRelativeDimension(y, props["y"], canvasSize.y);
    
    this->widget = new WG_TextInput(config);
  }
  if (widget == "WG_Button") {
    auto *config = new WGConfig_Button();
    
    config->label = props["label"];
    config->x = getRelativeDimension(x, props["x"], canvasSize.x);
    config->y = getRelativeDimension(y, props["y"], canvasSize.y);
    config->scriptFunction = props["scriptFunction"];
    
    this->widget = new WG_Button(config);
  }
  if (widget == "WG_Window") {
    auto *config = new WGConfig_Window();
    
    config->colour.r = props["colour"]["r"];
    config->colour.g = props["colour"]["g"];
    config->colour.b = props["colour"]["b"];
    config->colour.a = props["colour"]["a"];
    if (props.contains("focusedColour")) {
      config->focusedColour->r = props["focusedColour"]["r"];
      config->focusedColour->g = props["focusedColour"]["g"];
      config->focusedColour->b = props["focusedColour"]["b"];
      config->focusedColour->a = props["focusedColour"]["a"];
    }
    config->width = getRelativeDimension(x, props["width"], canvasSize.x);
    config->height = getRelativeDimension(y, props["height"], canvasSize.y);
    config->x = getRelativeDimension(x, props["x"], canvasSize.x);
    config->y = getRelativeDimension(y, props["y"], canvasSize.y);
    
    this->widget = new WG_Window(config);
  }
}
