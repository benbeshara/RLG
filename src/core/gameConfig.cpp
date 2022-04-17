//
// Created by Ben Beshara on 17/4/2022.
//

#include <fstream>
#include "gameConfig.h"
#include "json.hpp"

gameConfig::gameConfig() noexcept {
  std::ifstream i("config.json");
  if (!i.is_open()) return;
  nlohmann::json j;
  i >> j;
  
  this->screenSizeX = j.value("screenSizeX", 1024);
  this->screenSizeY = j.value("screenSizeY", 768);
  this->frameRate = j.value("frameRate", 60);
  this->initScript = j.value("initScript", "./assets/init.chai");
}
