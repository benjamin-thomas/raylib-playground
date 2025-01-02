// main.c
#include "log.h"
#include <dlfcn.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define SHARED_LIB "./build/lib.so"

typedef void (*update_func)(void);

int main() {
  void *shared_lib_handle = NULL;
  update_func update = NULL;
  time_t last_modified = 0;

  const int screenWidth = 1600;
  const int screenHeight = (int)((float)screenWidth * 9.f / 16.f);

  InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    // Check if shared library has been modified
    struct stat attr;
    stat(SHARED_LIB, &attr);

    // Reload the library if it's been modified
    if (attr.st_mtime > last_modified) {
      printf("Detected changes in library, reloading...\n");

      if (shared_lib_handle != NULL)
        dlclose(shared_lib_handle);

      shared_lib_handle = dlopen(SHARED_LIB, RTLD_NOW);
      if (!shared_lib_handle)
        die("Error loading library: %s\n", dlerror());

      // Get the function pointer
      update = (update_func)dlsym(shared_lib_handle, "update");
      if (!update)
        die("Error loading symbol: %s\n", dlerror());

      last_modified = attr.st_mtime;
      printf("Library reloaded successfully!\n");
    }

    update();
  } // while (1)

  if (shared_lib_handle)
    dlclose(shared_lib_handle);

  return 0;
}