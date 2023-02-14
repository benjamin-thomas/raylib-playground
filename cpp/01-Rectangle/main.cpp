#include <raylib.h>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const char *SCREEN_TITLE = "Hello Raylib!";
const float SPEED = 0.3;
const int REC3_SIZE = 200;

int main() {
    // Init
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

    // Init objects
    Vector2 pos{0, 0};
    Vector2 size{150, 150};
    auto rec = Rectangle{(float) GetScreenWidth() - REC3_SIZE, 0, REC3_SIZE, REC3_SIZE};
    float rotation = 0;

    // Game loop
    while (!WindowShouldClose()) {
        // Update
        if ((pos.x + size.x) < (float) GetScreenWidth()) {
            pos.x += 1 * SPEED;
        }
        if ((pos.y + size.y) < (float) GetScreenHeight()) {
            pos.y += 2 * SPEED;
        }

        if (rec.x > 0) {
            rec.x -= 1 * SPEED;
            rotation += 1 * SPEED;
        }
        if ((rec.y + rec.height) < (float) GetScreenHeight()) {
            rec.y += 0.5f * SPEED;
        }

        // Render
        BeginDrawing();
        ClearBackground(WHITE);

        DrawRectanglePro(rec, Vector2{rec.height/2, rec.width/2}, rotation, PINK);
        DrawRectangleRec(rec, VIOLET);
        DrawRectangle(10, 10, 100, 100, RED);
        DrawRectangleV(pos, size, ORANGE);

        EndDrawing();
    }

    // Cleanup
    CloseWindow();
    return 0;
}
