#include <raylib.h>

void update(void) {
  BeginDrawing();

  ClearBackground(PURPLE);
  DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

  EndDrawing();
}