#ifndef STATE_H
#define STATE_H

#include <raylib.h>

#define MAX_COLUMNS 20

#define WORLD_SIZE_X 16
#define WORLD_SIZE_Y 16
#define WORLD_SIZE_Z 16

typedef struct {
  Camera camera;
  bool is_window_focused;
  Texture2D atlas;
  int atlas_idx;
  Vector3 preview_block_pos;
  int world[WORLD_SIZE_X][WORLD_SIZE_Y][WORLD_SIZE_Z];
} State;

void state_init(State* state, bool reload);

void state_unload(State* state);

#endif
