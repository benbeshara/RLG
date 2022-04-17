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

protected:
  int screenSizeX = 1024;
  int screenSizeY = 768;
  int frameRate = 30;
  std::string initScript;
};


#endif //RLG_CMAKE_GAMECONFIG_H
