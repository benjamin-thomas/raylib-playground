#include <raylib.h>

#include "state.h"

void update(State *state) {
  if (IsKeyPressed(KEY_F1)) {
    printf("Resetting state!\n");
    state_init(state);
  }

  state->counter++;
  BeginDrawing();

  Color color = BLUE;
  int counter = state->counter;
  if (counter >= 100) color = ORANGE;
  if (counter >= 200) color = PURPLE;
  ClearBackground(color);

  DrawText(TextFormat("Counter (wait til 100, then 200): %d", state->counter),
           190, 200, 20, LIGHTGRAY);

  EndDrawing();
}
