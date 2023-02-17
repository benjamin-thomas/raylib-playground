using Raylib_CsLo;

namespace _00_HelloRaylib
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            // Setup
            Raylib.InitWindow(1280, 720, "Hello, Raylib-CsLo");
            Raylib.SetTargetFPS(60);
            var posX = 0;
            var dir = 1;
            const int approxTextWidth = 300;

            while (!Raylib.WindowShouldClose())
            {
                // Update
                if (posX < 0 || posX > Raylib.GetScreenWidth() - approxTextWidth)
                {
                    dir *= -1;
                }

                posX += 10 * dir;

                // Render
                Raylib.BeginDrawing();
                Raylib.ClearBackground(Raylib.SKYBLUE);
                Raylib.DrawFPS(10, 10);

                Raylib.DrawText("Hello from C#2!", posX, 360, 50, Raylib.RED);
                Raylib.EndDrawing();
            }

            // Cleanup
            Raylib.CloseWindow();
        }
    }
}