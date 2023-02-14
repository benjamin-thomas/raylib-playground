#include <raylib.h>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const char *SCREEN_TITLE = "Hello Raylib!";

int main() {
    // Init
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

    // Game loop
    while (!WindowShouldClose()) {
        // Update
        const Vector2 &pos = Vector2{300, 300};
        const Vector2 &pos2 = Vector2{450, 400};
        const Rectangle &rec = Rectangle{50, 150, 100, 200};

        // Render
        BeginDrawing();
        ClearBackground(Color{13, 17, 23, 255});

        DrawCircleV(pos, 50, GOLD);
        DrawCircleLines((int) pos.x, (int) pos.y, 50, WHITE);
        DrawCircleGradient((int) pos.x, (int) pos.y, 40, PINK, SKYBLUE);
        DrawCircleGradient(300, 100, 70, SKYBLUE, BLACK);
        DrawCircleSector(pos2, 100, 0, 180, 4, PINK);
        DrawCircleSectorLines(pos2, 100, 0, 180, 4, GREEN);
        DrawEllipse(100, 100, 50, 30, ORANGE);
        DrawEllipseLines(100, 100, 50, 30, RED);
        DrawRectangleRounded(rec, 0.4, 100, GOLD);

        EndDrawing();
    }

    // Cleanup
    CloseWindow();
    return 0;
}
