#include <raylib.h>

 int main()
{
    InitWindow(1500, 950, "ColourSequence");
    SetTargetFPS(30);

    while (!WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Colour Sequence Game", 500, 300, 50, WHITE);
        DrawRectangle(600, 400, 50, 25, BLUE);
        DrawRectangle(625, 400, 25, 25, ORANGE);
        DrawRectangle(650, 400, 25, 25, GREEN);
        DrawRectangle(675, 400, 25, 25, RED);
        DrawRectangle(700, 400, 25, 25, PURPLE);
        DrawRectangle(725, 400, 25, 25, YELLOW);
        DrawRectangle(750, 400, 25, 25, PINK);
        DrawRectangle(775, 400, 25, 25, MAROON);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
