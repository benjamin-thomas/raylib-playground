#include <raylib.h>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const char *SCREEN_TITLE = "Hello Raylib!";

int main() {
    // Init
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
    auto v1 = Vector2{200, 200};
    auto v2 = Vector2{400, 200};
    auto v3 = Vector2{300, 100};

    // Game loop
    while (!WindowShouldClose()) {
        // Update

        // Render
        BeginDrawing();
        ClearBackground(Color{13, 17, 23, 255});
        DrawTriangle(v1, v2, v3, BLUE);
        DrawTriangleLines(v1, v2, v3, RED);

        EndDrawing();
    }

    // Cleanup
    CloseWindow();
    return 0;
}
