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

        // Render
        BeginDrawing();
        ClearBackground(Color{13, 17, 23, 255});

        DrawLine(100, 100, 500, 100, BLUE);
        DrawLineEx(Vector2{200, 200}, Vector2{400, 300}, 4, PINK);

        Vector2 bottom;
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            bottom = GetMousePosition();
        } else {
            bottom = Vector2{300, 500};
        }
        DrawLineBezier(Vector2{50, 200}, bottom, 6, ORANGE);
        DrawLineBezier(bottom, Vector2{550, 200}, 6, RED);
        DrawLineBezierCubic(Vector2{50, 200}, bottom,
                            Vector2{0, 0}, Vector2{300, 10},
                            4, DARKGRAY);
        DrawLineBezierCubic(bottom, Vector2{550, 200},
                            Vector2{300, 10}, Vector2{600, 20},
                            4, DARKPURPLE);

        DrawLineBezierQuad(Vector2{50, 400}, Vector2{550, 400},
                           Vector2{300, 700},
                           4, BROWN);
        EndDrawing();
    }

    // Cleanup
    CloseWindow();
    return 0;
}
