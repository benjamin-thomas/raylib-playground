#ifndef STATE_H
#define STATE_H

#include <stdio.h>
typedef struct {
  int counter;
} State;

void state_init(State *state);

#endif