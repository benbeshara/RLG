//
// Created by Ben Beshara on 4/4/2022.
//

#ifndef RLG_CMAKE_GUIBUILDER_H
#define RLG_CMAKE_GUIBUILDER_H


#include "json.hpp"
#include "widget.h"

class guiBuilder {
public:
    guiBuilder(std::string widget, nlohmann::json props);

    Widget* widget;
};


#endif //RLG_CMAKE_GUIBUILDER_H
