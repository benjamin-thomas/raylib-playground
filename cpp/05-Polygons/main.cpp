#include <raylib.h>
#include <math.h>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const char *SCREEN_TITLE = "Hello Raylib!";

int main() {
    // Init
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

    // Game loop
    while (!WindowShouldClose()) {
        // Update
        float time = GetTime();
        float x = sin(time);

        // Render
        BeginDrawing();
        ClearBackground(Color{13, 17, 23, 255});

        DrawPoly(Vector2{300, 100}, 5, 100,
                 (180 + 20 * x), ORANGE); // point upwards (180), and tilt (-20 => 20)

        DrawPolyLinesEx(Vector2{300, 300}, 9, 100,
                        180 * x, 12, PINK);
        DrawPolyLinesEx(Vector2{300, 300}, 9, 96,
                        180 * x, 3, DARKPURPLE);

        EndDrawing();
    }

    // Cleanup
    CloseWindow();
    return 0;
}
