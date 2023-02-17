#include <raylib.h>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const char *SCREEN_TITLE = "Hello Raylib!";

int main() {
    // Init
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
    const Font &cartoonFont = LoadFont("../res/fonts/Cartoon_Regular.ttf");
    // https://github.com/raysan5/raylib/blob/master/examples/text/resources/fonts/alagard.png
    const Font &alagardFont = LoadFont("../res/fonts/alagard.png");

    // Game loop
    while (!WindowShouldClose()) {
        // Update

        // Render
        BeginDrawing();
        ClearBackground(Color{13, 17, 23, 255});

        DrawText("Hello with the builtin font!", 10, 0, 25, ORANGE);

        DrawTextEx(cartoonFont, "Hello with a custom (ttf) font!",
                   Vector2{10, 40}, 50, 1, ORANGE);

        DrawTextEx(alagardFont, "Hello with a custom (png) font!",
                   Vector2{10, 100}, 36, 1, ORANGE);

        DrawFPS(10, GetScreenHeight()-30);
        EndDrawing();
    }

    // Cleanup
    CloseWindow();
    return 0;
}
