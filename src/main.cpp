#include "core/execCtx.h"
#include "core/state.h"
#include "core/widget.h"
#include "core/GameStore.h"

int main() {
  GameStore *store = GameStore::GetInstance();
  
  const int screenWidth = 800;
  const int screenHeight = 450;
  
  InitWindow(screenWidth, screenHeight, "Widget UI Demo");
  
  SetTargetFPS(60);
  
  store->getScript()->loadBuffer("./assets/init.chai");
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