//
// Created by Ben Beshara on 17/4/2022.
//

#ifndef RLG_CMAKE_GAMECONFIG_H
#define RLG_CMAKE_GAMECONFIG_H


#include <string>
#include "raylib.h"

class gameConfig {
public:
  enum E_CONFIG {
    SCREEN_SIZE_X,
    SCREEN_SIZE_Y,
    FRAMERATE,
    INIT_SCRIPT,
    DEBUG_DRAW,
    FONT,
    SNAPSIZE
  };
  
  gameConfig() noexcept;
  
  template<typename ValueType>
  int setConfig(gameConfig::E_CONFIG key, ValueType value);
  
  template<>
  int setConfig(gameConfig::E_CONFIG key, int value) {
    switch (key) {
      case SCREEN_SIZE_X:
        this->screenSizeX = value;
        break;
      case SCREEN_SIZE_Y:
        this->screenSizeY = value;
        break;
      case FRAMERATE:
        this->frameRate = value;
        break;
      case DEBUG_DRAW:
        this->debugDraw = value;
        break;
      case SNAPSIZE:
        this->snapSize = value;
        break;
      default:
        TraceLog(LOG_WARNING, "gameConfig.cpp: Cannot set unknown config value");
        return 1;
    }
    return 0;
  }
  
  template<>
  int setConfig(gameConfig::E_CONFIG key, std::string value) {
    switch (key) {
      case INIT_SCRIPT:
        this->initScript = value;
        break;
      default:
        TraceLog(LOG_WARNING, "gameConfig.cpp: Cannot set unknown config value");
        return 1;
    }
    return 0;
  }
  
  template<>
  int setConfig(gameConfig::E_CONFIG key, Font value) {
    switch (key) {
      case FONT:
        this->defaultFont = value;
        break;
      default:
        TraceLog(LOG_WARNING, "gameConfig.cpp: Cannot set unknown config value");
        return 1;
    }
    return 0;
  }
  
  
  template<typename ReturnType>
  ReturnType getConfig(gameConfig::E_CONFIG key);
  
  template<>
  int getConfig(gameConfig::E_CONFIG key) {
    switch (key) {
      case SCREEN_SIZE_X:
        return this->screenSizeX;
      
      case SCREEN_SIZE_Y:
        return this->screenSizeY;
      
      case FRAMERATE:
        return this->frameRate;
      
      case DEBUG_DRAW:
        return this->debugDraw;
      
      case SNAPSIZE:
        return this->snapSize;
      
      default:
        TraceLog(LOG_WARNING, "gameConfig.cpp: Cannot get unknown config value");
        return 0;
    }
  }
  
  template<>
  std::string getConfig(gameConfig::E_CONFIG key) {
    switch (key) {
      case INIT_SCRIPT:
        return this->initScript;
      
      default:
        TraceLog(LOG_WARNING, "gameConfig.cpp: Cannot get unknown config value");
        return "";
    }
  }
  
  template<>
  Font getConfig(gameConfig::E_CONFIG key) {
    switch (key) {
      case FONT:
        return this->defaultFont;
      
      default:
        TraceLog(LOG_WARNING, "gameConfig.cpp: Cannot get unknown config value");
        return GetFontDefault();
    }
  }
  
  void LoadFonts();

protected:
  int screenSizeX = 1024;
  int screenSizeY = 768;
  int frameRate = 30;
  std::string initScript;
  int debugDraw = false;
  std::string defaultFontName = "default.ttf";
  Font defaultFont;
  int snapSize = 1;
};


#endif //RLG_CMAKE_GAMECONFIG_H
