#include <raylib.h>
#include <vector>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const char *SCREEN_TITLE = "Hello Raylib!";

int main() {
    // Init
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

    // static array data (length is set at compile time)
    Color colors[] = {
            GOLD,
            RED,
            GREEN,
            BLUE,
            PURPLE,
            SKYBLUE,
            ORANGE,
            PINK,
            LIME,
            BEIGE,
    };

    // std::vector is for dynamic array data
    std::vector<Vector2> pixels;

    // Game loop
    while (!WindowShouldClose()) {
        // Update
        pixels.clear();
        for (int i = 0; i < 50'000; ++i) {
            auto pixel = Vector2{
                    static_cast<float>(GetRandomValue(0, GetScreenWidth())),
                    static_cast<float>(GetRandomValue(0, GetScreenHeight())),
            };
            pixels.push_back(pixel);
        }

        // Render
        BeginDrawing();
        ClearBackground(Color{13, 17, 23, 255});

        for (const auto &p: pixels) {
            DrawPixel((int) p.x, (int) p.y,
                      colors[GetRandomValue(0, sizeof(colors) - 1)]);
        }

        EndDrawing();
    }

    // Cleanup
    CloseWindow();
    return 0;
}
