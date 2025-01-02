#ifndef STATE_H
#define STATE_H

#include <raylib.h>

#define MAX_COLUMNS 20

typedef struct {
  Camera camera;
  Vector3 cubePosition;
  bool isFocused;
} State;

void state_init(State* state);

#endif
