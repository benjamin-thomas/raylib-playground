#include "state.h"

#include <stdio.h>

void state_init(State *state) {
  // Define the camera to look into our 3d world
  Camera3D camera = {0};
  camera.position = (Vector3){10.0f, 10.0f, 10.0f};  // Camera position
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};       // Camera looking at point
  camera.up = (Vector3){0.0f, 1.0f,
                        0.0f};  // Camera up vector (rotation towards target)
  camera.fovy = 45.0f;          // Camera field-of-view Y
  camera.projection = CAMERA_PERSPECTIVE;  // Camera projection type

  Vector3 cubePosition = {0.0f, 0.0f, 0.0f};

  state->camera = camera;
  state->cubePosition = cubePosition;
  state->isFocused = true;
  printf("State initialized\n");
}
