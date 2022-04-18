//
// Created by Ben Beshara on 4/4/2022.
//

#ifndef RLG_CMAKE_GUIBUILDER_H
#define RLG_CMAKE_GUIBUILDER_H


#include "json.hpp"
#include "widget.h"
#include "widget_container_draggable.h"

class guiBuilder {
public:
  guiBuilder(const std::string &widget, nlohmann::json props, Vector2 canvasSize);
  
  Widget *widget;
};


#endif //RLG_CMAKE_GUIBUILDER_H
