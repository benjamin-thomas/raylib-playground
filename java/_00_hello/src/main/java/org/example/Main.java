package org.example;

import static com.raylib.Jaylib.RAYWHITE;
import static com.raylib.Jaylib.VIOLET;
import static com.raylib.Raylib.*;

/*
    ./gradlew run
 */
public class Main {
    public static void main(String[] args) {
        // Init
        InitWindow(800, 450, "Demo");
        SetTargetFPS(60);
        int x = 0;
        int dir = 1;
        int approxTextSize = 300;

        while (!WindowShouldClose()) {
            // Update
            x += dir * 5;
            if (x < 0 || x > GetScreenWidth() - approxTextSize) {
                dir *= -1;
            }

            // Render
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Hello Raylib from Java (jaylib)", x, 200, 20, VIOLET);
            DrawFPS(20, 20);
            EndDrawing();
        }

        // Cleanup
        CloseWindow();
    }
}