#ifndef STATE_H
#define STATE_H

#include <raylib.h>

#define MAX_COLUMNS 20

typedef struct {
  Camera camera;
  bool is_window_focused;
  Texture2D atlas;
  int atlas_idx;
} State;

void state_init(State* state, bool reload);

void state_unload(State* state);

#endif
