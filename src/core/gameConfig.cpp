//
// Created by Ben Beshara on 17/4/2022.
//

#include <fstream>
#include "gameConfig.h"
#include "json.hpp"
#include "raylib.h"

gameConfig::gameConfig() noexcept {
  // Check to see if we have the config in JSON
  // If we do, convert it to CBOR and load that instead
  // Otherwise, go straight to the CBOR
  std::ifstream i;
  i.open("config.json");
  
  if (i.is_open()) {
    nlohmann::json j;
    i >> j;
    std::ofstream o;
    o.open("config.bin");
    nlohmann::json::to_cbor(j, o);
    o.close();
    i.close();
  }
  
  i.open("config.bin");
  if (!i.is_open()) {
    TraceLog(LOG_WARNING, "Config file not found!");
    return;
  }
  
  nlohmann::json j = nlohmann::json::from_cbor(i);
  
  this->screenSizeX = j.value("screenSizeX", 1024);
  this->screenSizeY = j.value("screenSizeY", 768);
  this->frameRate = j.value("frameRate", 60);
  this->initScript = j.value("initScript", "./assets/init.chai");
  this->debugDraw = j.value("debugDraw", false);
  this->defaultFontName = j.value("defaultFontName", "default.ttf");
}

// Fonts must be loaded after window init, so we call this explicitly afterward
void gameConfig::LoadFonts() {
  char fontName[256];
  sprintf(fontName, "assets/%s", this->defaultFontName.c_str());
  
  Font font = LoadFontEx(
      fontName,
      32,
      nullptr,
      250
  );
  
  this->defaultFont = font;
}