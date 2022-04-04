#include "core/execCtx.h"
#include "core/state.h"
#include "core/widget.h"

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 450;
  
  InitWindow(screenWidth, screenHeight, "Widget UI Demo");
  
  SetTargetFPS(60);
  
  State gameState;
  execCtx script(&gameState);
  
  script.loadBuffer("./assets/init.chai");
  script.run();
  
  while (!WindowShouldClose()) {
    BeginDrawing();
    
    ClearBackground(RAYWHITE);
    
    gameState.GameLoop();
    
    EndDrawing();
  }
  
  CloseWindow();
  
  return 0;
}