//
// Created by Ben Beshara on 4/4/2022.
//

#include "guiBuilder.h"
#include "json.hpp"
#include "../widgets/WG_TextInput.h"

guiBuilder::guiBuilder(std::string widget, nlohmann::json props){
    if(widget == "WG_TextInput"){
        WGConfig_TextInput* config = new WGConfig_TextInput();

        config->text = props["text"];
        config->x = props["x"];
        config->y = props["y"];

        this->widget = new WG_TextInput(config);
    }
}
