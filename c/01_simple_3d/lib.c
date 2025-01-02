#include <raylib.h>
#include <stdio.h>

#include "state.h"

void draw_3d(State* state) {
  BeginMode3D(state->camera);

  DrawCube(state->cubePosition, 2.0f, 2.0f, 2.0f, GREEN);
  DrawCubeWires(state->cubePosition, 2.0f, 2.0f, 2.0f, LIME);

  DrawGrid(8, 1.0f);

  EndMode3D();
}

void draw(State* state) {
  BeginDrawing();

  ClearBackground(RAYWHITE);

  draw_3d(state);

  DrawRectangle(10, 10, 500, 93, Fade(SKYBLUE, 0.5f));
  DrawRectangleLines(10, 10, 500, 93, BLUE);

  const char* cameraPositionText =
      TextFormat("Camera Position: (%02f,%02f, %02f)", state->camera.position.x,
                 state->camera.position.y, state->camera.position.z);

  DrawText(cameraPositionText, 20, 25, 20, BLACK);

  const char* cameraTargetText =
      TextFormat("Camera Target: (%02f,%02f, %02f)", state->camera.target.x,
                 state->camera.target.y, state->camera.target.z);

  DrawText(cameraTargetText, 20, 55, 20, BLACK);

  EndDrawing();
}

void update_state(State* state) {
  if (IsKeyPressed(KEY_F1)) {
    printf("Resetting state!\n");
    state_init(state);
  }

  if (IsKeyPressed('X')) {
    state->isFocused = !state->isFocused;
    if (state->isFocused) {
      DisableCursor();
    } else {
      EnableCursor();
    }
  }

  if (state->isFocused) UpdateCamera(&state->camera, CAMERA_FREE);

  if (IsKeyPressed('Z')) {
    state->camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  }
}

void update(State* state) {
  update_state(state);
  draw(state);
}