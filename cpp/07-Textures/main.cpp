#include <raylib.h>
#include <cmath>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const char *SCREEN_TITLE = "Hello Raylib!";

int main() {
    // Init
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
    const Texture2D &pinkPanther = LoadTexture("../res/images/PinkPanther.png");
    bool isLightOn = false;

    // Game loop
    while (!WindowShouldClose()) {
        // Update
        double x = sin(GetTime()) * 75;
        double y = cos(GetTime()) * 10;

        if (IsKeyPressed(KEY_SPACE)) {
            isLightOn = !isLightOn;
        }

        // Render
        BeginDrawing();
        ClearBackground(Color{13, 17, 23, 255});

//        DrawTextureTiled(pinkPanther,
//                         Rectangle{150, 0, 250, 140}, // crop
//                         Rectangle{0, 0, SCREEN_WIDTH, SCREEN_HEIGHT},
//                         Vector2{0, 0},
//                         0,
//                         1,
//                         Color{8, 8, 8, 128}
//        );

        // Other way to tile
        DrawTextureQuad(
                pinkPanther,
                Vector2{5, 4}, // repeat x, repeat y
                Vector2{0.5f, 0.5f},
                Rectangle{0, 0, SCREEN_WIDTH, SCREEN_HEIGHT},
                Color{8, 8, 8, 128}
        );

        DrawTexture(pinkPanther, 50, 50, isLightOn ? WHITE : BROWN);
        DrawTextureEx(
                pinkPanther,
                Vector2{50 + (float) x, 50 + (float) y},
                45 + (float) y,
                1,
                isLightOn ? WHITE : BROWN
        );
        DrawTextureRec(pinkPanther,
                       Rectangle{150, 0, 250, 140}, // crop
                       Vector2{0, 0},
                       isLightOn ? BLUE : BROWN
        );
        DrawText("Press SPACE to turn the light ON and OFF!", 10, GetScreenHeight()-35, 25, ORANGE);

        EndDrawing();
    }

    // Cleanup
    CloseWindow();
    return 0;
}
