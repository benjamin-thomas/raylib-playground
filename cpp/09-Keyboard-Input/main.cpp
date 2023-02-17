#include <raylib.h>
#include <string>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const char *SCREEN_TITLE = "Hello Raylib!";

int main() {
    // Init
    SetConfigFlags(FLAG_MSAA_4X_HINT);      // Enable Multi Sampling Anti Aliasing 4x (if available)

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
    auto pos = Vector2{SCREEN_WIDTH / 2.0, SCREEN_HEIGHT / 2.0};
    auto prevTime = (float) GetTime();
    float velocity = 600;

//    DisableCursor();

    // Game loop
    while (!WindowShouldClose()) {
        auto deltaTime = (float) GetTime() - prevTime;
        prevTime = (float) GetTime();
        // Update
        const Color &color = IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? RED : ORANGE;
        const Color &color2 = IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? GREEN : YELLOW;

        if (IsKeyDown(KEY_UP)) {
            pos.y -= velocity * deltaTime;
        }
        if (IsKeyDown(KEY_DOWN)) {
            pos.y += velocity * deltaTime;
        }
        if (IsKeyDown(KEY_LEFT)) {
            pos.x -= velocity * deltaTime;
        }
        if (IsKeyDown(KEY_RIGHT)) {
            pos.x += velocity * deltaTime;
        }



        // Render
        BeginDrawing();
        ClearBackground(Color{13, 17, 23, 255});

        DrawRectangle((int) pos.x, (int) pos.y, 100, 100, color2);
        const Vector2 &mousePos = GetMousePosition();
        const Vector2 &recSize = Vector2{100, 100};
        DrawRectangleV(Vector2{mousePos.x-(recSize.x/2), mousePos.y-(recSize.y/2)}, recSize, color);
        DrawLineBezier(Vector2{0, 0}, mousePos, 7, color);
        DrawCircleV(mousePos, 25, BLUE);
        DrawText(std::to_string(deltaTime).c_str(), 10, 10, 30, BLUE);
        DrawText("Use arrows to move the yellow square", 10, GetScreenHeight() - 40, 28, PURPLE);
        DrawText("Use mouse left click to change color", 10, GetScreenHeight() - 80, 28, PURPLE);

        EndDrawing();
    }

    // Cleanup
    CloseWindow();
    return 0;
}
