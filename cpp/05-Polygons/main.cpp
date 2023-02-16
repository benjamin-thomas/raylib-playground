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
        auto time = (float) GetTime();
        float x = sin(time);

        float x2 = sin(time) / 2.0f + 0.5f;
        float y2 = cos(time) / 2.0f + 0.5f;

        auto red = (unsigned char) (255 * x2);
        const Color &orange = Color{red, 161, 0, 255};

        const Color &pink = Color{red, 109, 194, 255};

        // Render
        BeginDrawing();
        ClearBackground(Color{13, 17, 23, 255});

        DrawPoly(Vector2{300, 100}, 5, 100,
                 (180 + 20 * x), orange); // point upwards (180), and tilt (-20 => 20)

        DrawPolyLinesEx(Vector2{300, 300}, 9, 100,
                        180 * x, 12, pink);
        DrawPolyLinesEx(Vector2{300, 300}, 9, 96,
                        180 * x, 3, DARKPURPLE);


        float recWidth = 300;
        float recX = (float) GetScreenWidth() / 2 - recWidth / 2;
        const Rectangle &rec = Rectangle{recX, 420, recWidth, 100};
        DrawRectangleGradientEx(rec,
                                Fade(BLUE, y2),
                                Fade(BLUE, y2),
                                Fade(RED, x2),
                                Fade(RED, x2)
                                );

        EndDrawing();
    }

    // Cleanup
    CloseWindow();
    return 0;
}
