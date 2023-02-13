#include <raylib.h>
#include <iostream>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
#define SCREEN_TITLE "Hello Raylib!"

int main() {
    // Init
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
    Vector2 pos{0, 0};

    // Game loop
    while (!WindowShouldClose()) {
        // Update
        pos.x += 1;
        pos.y += 2;

        // Render
        BeginDrawing();
        if ((int) pos.x % 1000 == 0) {
            std::cout << "X=" << pos.x << "\t" "Y=" << pos.y << std::endl;
        }
        ClearBackground(ORANGE);
        DrawRectangle(10, 10, 100, 100, RED);
        EndDrawing();
    }

    // Cleanup
    CloseWindow();
    return 0;
}
