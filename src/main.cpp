#include "core/execCtx.h"
#include "core/state.h"
#include "core/widget.h"
#include "core/GameStore.h"

int main() {
  SetTraceLogLevel(LOG_INFO);
  GameStore *store = GameStore::GetInstance();
  
  const int screenWidth = store->getConfig()->getConfig<int>(gameConfig::E_CONFIG::SCREEN_SIZE_X);
  const int screenHeight = store->getConfig()->getConfig<int>(gameConfig::E_CONFIG::SCREEN_SIZE_Y);
//  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(screenWidth, screenHeight, "Widget UI Demo");
  
  SetTargetFPS(store->getConfig()->getConfig<int>(gameConfig::E_CONFIG::FRAMERATE));
  
  store->getScript()->loadBuffer(store->getConfig()->getConfig<std::string>(gameConfig::E_CONFIG::INIT_SCRIPT));
  store->getScript()->run();
  
  while (!WindowShouldClose()) {
    BeginDrawing();
    
    ClearBackground(RAYWHITE);
    
    store->getState()->GameLoop();
    
    EndDrawing();
  }
  
  CloseWindow();
  
  return 0;
}