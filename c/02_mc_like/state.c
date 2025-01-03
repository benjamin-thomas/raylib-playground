#include "state.h"

#define GLSL_VERSION 330

void state_init(State *state, bool reload) {
  state->camera = (Camera3D){
      .position = (Vector3){3.0f, 3.0f, 3.0f},
      .target = (Vector3){0.0f, 0.0f, 0.0f},
      .up = (Vector3){0.0f, 1.0f, 0.0f},
      .fovy = 45.0f,
      .projection = CAMERA_PERSPECTIVE,
  };

  state->preview_block_pos = (Vector3){0.0f, 0.0f, 0.0f};
  state->atlas_idx = 1;  // grass

  if (!reload) {
    state->is_window_focused = true;
    state->atlas = LoadTexture("resources/atlas.png");
  }

  // Set the texture tiling using a shader
  float tiling[2] = {3.0f, 3.0f};
  Shader shader = LoadShader(
      0, TextFormat("resources/shaders/glsl%i/tiling.fs", GLSL_VERSION));

  SetShaderValue(shader, GetShaderLocation(shader, "tiling"), tiling,
                 SHADER_UNIFORM_VEC2);

  // Initialize world to empty (all air blocks)
  for (int x = 0; x < WORLD_SIZE_X; x++) {
    for (int y = 0; y < WORLD_SIZE_Y; y++) {
      for (int z = 0; z < WORLD_SIZE_Z; z++) {
        state->world[x][y][z] = 0;
      }
    }
  }

  // Create a simple ground plane with grass blocks
  for (int x = 0; x < WORLD_SIZE_X; x++) {
    for (int z = 0; z < WORLD_SIZE_Z; z++) {
      state->world[x][0][z] = 1;  // Grass block type
    }
  }

  TraceLog(LOG_INFO, ">>> State initialized");
}

void state_unload(State *state) {
  UnloadTexture(state->atlas);
  TraceLog(LOG_INFO, ">>> State unloaded");
}
