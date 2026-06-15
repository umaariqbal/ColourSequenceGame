#include <raylib.h>
#include <cstdlib>
#include <ctime>

int main()
{
    InitWindow(800, 600, "Colour Sequence Game");
    SetTargetFPS(60);

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // 4 colours
    Color colours[4] =
    {
        RED,
        BLUE,
        GREEN,
        YELLOW
    };

    // random sequence
    int sequence[9];

    for(int i = 0; i < 9; i++)
    {
        sequence[i] = rand() % 4;
    }

    int currentIndex = 0;

    bool showSequence = true;
    bool gameWon = false;
    bool gameOver = false;

    float timer = 0;

    while(!WindowShouldClose())
    {
        timer += GetFrameTime();

        // show sequence for 5 seconds
        if(timer > 5)
        {
            showSequence = false;
        }

        // Button positions
        Rectangle redButton    = {150, 400, 100, 100};
        Rectangle blueButton   = {300, 400, 100, 100};
        Rectangle greenButton  = {450, 400, 100, 100};
        Rectangle yellowButton = {600, 400, 100, 100};

        if(!showSequence && !gameWon)
        {
            Vector2 mouse = GetMousePosition();

            int clickedColour = -1;

            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                if(CheckCollisionPointRec(mouse, redButton))
                    clickedColour = 0;

                if(CheckCollisionPointRec(mouse, blueButton))
                    clickedColour = 1;

                if(CheckCollisionPointRec(mouse, greenButton))
                    clickedColour = 2;

                if(CheckCollisionPointRec(mouse, yellowButton))
                    clickedColour = 3;

                if(clickedColour != -1)
                {
                    if(clickedColour == sequence[currentIndex])
                    {
                        currentIndex++;

                        if(currentIndex == 9)
                        {
                            gameWon = true;
                        }
                    }
                    else
                    {
                        gameOver = true;

                        // create new sequence
                        for(int i = 0; i < 9; i++)
                        {
                            sequence[i] = std::rand() % 4;
                        }

                        currentIndex = 0;
                        timer = 0;
                        showSequence = true;
                    }
                }
            }
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("MEMORY COLOUR GAME", 220, 30, 30, BLACK);

        // show sequence
        if(showSequence)
        {
            DrawText("MEMORIZE THE SEQUENCE", 220, 80, 25, DARKGRAY);

            for(int i = 0; i < 9; i++)
            {
                DrawRectangle(
                    50 + i * 80,
                    180,
                    60,
                    60,
                    colours[sequence[i]]
                );
            }
        }
        else
        {
            DrawText("CLICK THE COLOURS IN ORDER", 200, 80, 25, DARKGRAY);

            for(int i = 0; i < 9; i++)
            {
                DrawRectangleLines(
                    50 + i * 80,
                    180,
                    60,
                    60,
                    BLACK
                );
            }
        }

        // colour buttons
        DrawRectangleRec(redButton, RED);
        DrawRectangleRec(blueButton, BLUE);
        DrawRectangleRec(greenButton, GREEN);
        DrawRectangleRec(yellowButton, YELLOW);

        DrawText("RED", 175, 440, 20, WHITE);
        DrawText("BLUE", 320, 440, 20, WHITE);
        DrawText("GREEN", 465, 440, 20, WHITE);
        DrawText("YELLOW", 610, 440, 20, BLACK);

        DrawText(TextFormat("Progress: %i / 9", currentIndex),
                 320, 320, 25, BLACK);

        if(gameWon)
        {
            DrawText("YOU WIN!",
                     310,
                     540,
                     40,
                     GREEN);
        }

        if(gameOver)
        {
            DrawText("WRONG! TRY AGAIN",
                     250,
                     540,
                     35,
                     RED);

            if(timer > 10)
            {
                gameOver = false;
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}