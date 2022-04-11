//
// Created by Ben Beshara on 4/4/2022.
//

#include "guiBuilder.h"
#include "json.hpp"
#include "../widgets/WG_TextInput.h"
#include "../widgets/WG_Window.h"
#include "../widgets/WG_Button.h"

guiBuilder::guiBuilder(const std::string &widget, nlohmann::json props,
                       const std::optional<Widget_Container_Draggable> &parent) {
  if (widget == "WG_TextInput") {
    auto *config = new WGConfig_TextInput();
    
    config->text = props["text"];
    config->x = props["x"];
    config->y = props["y"];
    
    this->widget = new WG_TextInput(config);
  }
  if (widget == "WG_Button") {
    auto *config = new WGConfig_Button();
    
    config->label = props["label"];
    config->x = props["x"];
    config->y = props["y"];
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
    config->width = props["width"];
    config->height = props["height"];
    config->x = props["x"];
    config->y = props["y"];
    
    this->widget = new WG_Window(config);
  }
}
