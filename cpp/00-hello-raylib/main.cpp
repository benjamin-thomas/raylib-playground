#include <raylib.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
#define SCREEN_TITLE "Hello Raylib!"

int main() {
    // Init
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

    // Game loop
    while (!WindowShouldClose()) {
        // Update

        // Render
        BeginDrawing();
        ClearBackground(ORANGE);
        DrawRectangle(10, 10, 100, 100, RED);
        EndDrawing();
    }

    // Cleanup
    CloseWindow();
    return 0;
}
