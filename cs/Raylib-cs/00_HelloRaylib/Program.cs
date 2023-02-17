using Raylib_cs;

namespace _00_HelloRaylib
{
    internal static class Program
    {
        public static void Main()
        {
            Raylib.InitWindow(800, 480, "Hello from C#!");

            while (!Raylib.WindowShouldClose())
            {
                Raylib.BeginDrawing();
                Raylib.ClearBackground(Color.BLACK);

                Raylib.DrawText("Hello, world!", 12, 12, 20, Color.BLACK);

                Raylib.EndDrawing();
            }

            Raylib.CloseWindow();
        }
    }
}