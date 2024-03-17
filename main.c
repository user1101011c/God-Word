#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "file_reading.h"




int main(void) {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Example");

    char fileContent[512] = "";
    

    // Рассчитываем размер и позицию текста
    const char* text = "Here you can find out what God is saying today.\n\n\n\t\t\t\t\t\t\t\t\tJust click on the button.";
    int fontSize = 20 * 2;
    int textWidth = MeasureText(text, fontSize);
    int textHeight = fontSize;
    int textX = (screenWidth - textWidth) / 2;
    int textY = screenHeight / 10; // Положим текст в верхнюю часть экрана

    // Позиция и размеры кнопки
    Rectangle buttonRec = { screenWidth / 2 - 100, 200, 200, 40 }; // 160 дефолтное значение для У

    // Булева переменная для хранения состояния кнопки
    bool buttonPressed = false;

    // Переменная для текстового поля
    char textFieldText[1000] = "";
    Rectangle textRec = { screenWidth / 2 - 300, screenHeight / 2 - 100, 600, 450 };

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Обновление состояния кнопки
        if (CheckCollisionPointRec(GetMousePosition(), buttonRec)) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                buttonPressed = !buttonPressed;
                file_reading();
                
            }
        }

        // Обновляем текст в текстовом поле
        int key = GetKeyPressed();
        if (key > 0 && strlen(textFieldText) < 63) {
            int len = strlen(textFieldText);
            textFieldText[len] = (char)key;
            textFieldText[len + 1] = '\0';
        }

        if (IsKeyPressed(KEY_BACKSPACE)) {
            int len = strlen(textFieldText);
            if (len > 0) textFieldText[len - 1] = '\0';
        }

        // Начало рисования
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText(text, textX, textY, fontSize, BLACK);

        // Рисуем кнопку
        // if (!buttonPressed) 
        DrawRectangleRec(buttonRec, DARKPURPLE);
        // else DrawRectangleRec(buttonRec, MAGENTA);
        
        DrawText("Press me!", buttonRec.x + buttonRec.width/2 - MeasureText("Press me!", 25)/2 + 10, buttonRec.y + 10, 20, WHITE);

        // Рисуем текстовое поле
        DrawRectangleRec(textRec, RAYWHITE);
        DrawRectangleLinesEx(textRec, 2, BLACK);
        // DrawText(textFieldText, textRec.x + 10, textRec.y + 10, 20, DARKGRAY);
        DrawText("Press 'ESC' to close window.", 20, 20, 15 * 2, BLACK);

        EndDrawing();
    }
    
    CloseWindow();
    
    return 0;
}