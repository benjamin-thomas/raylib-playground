// main.c
#include <dlfcn.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "log.h"
#include "state.h"

#define SHARED_LIB "./build/lib.so"

typedef void (*update_func)(State *state);

int main() {
  void *shared_lib_handle = NULL;
  update_func update = NULL;
  time_t last_modified = 0;

  const int screenWidth = 1920;
  const int screenHeight = (int)((float)screenWidth * 10.f /
                                 16.f);  // my internal monitor has 16/10 ratio

  InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

  int targetMonitor =
      1;  // (for my setup: 0 = external monitor, 1 = internal monitor)
  TraceLog(LOG_INFO, ">>> Target monitor: %d", targetMonitor);
  TraceLog(LOG_INFO, ">>> Monitor count: %d", GetMonitorCount());
  if (targetMonitor < GetMonitorCount()) {
    TraceLog(LOG_WARNING, ">>> Switching to monitor: %d", targetMonitor);
    SetWindowMonitor(targetMonitor);

    // The following 2 functions don't work well with my setup, don't use them.
    // ToggleBorderlessWindowed();
    // ToggleFullscreen();
  } else {
    TraceLog(LOG_WARNING, ">>> Invalid monitor index: %d", targetMonitor);
  }

  SetTargetFPS(60);

  State state;
  state_init(&state);

  while (!WindowShouldClose()) {
    // Check if shared library has been modified
    struct stat attr;
    stat(SHARED_LIB, &attr);

    // Reload the library if it's been modified
    if (attr.st_mtime > last_modified) {
      printf("Detected changes in library, reloading...\n");

      if (shared_lib_handle != NULL) dlclose(shared_lib_handle);

      shared_lib_handle = dlopen(SHARED_LIB, RTLD_NOW);
      if (!shared_lib_handle) die("Error loading library: %s\n", dlerror());

      // Get the function pointer
      update = (update_func)dlsym(shared_lib_handle, "update");
      if (!update) die("Error loading symbol: %s\n", dlerror());

      last_modified = attr.st_mtime;
      printf("Library reloaded successfully!\n");
    }

    update(&state);
  }  // while (1)

  if (shared_lib_handle) dlclose(shared_lib_handle);

  return 0;
}