#include "raylib.h"

//Scene stuff 
typedef enum {
    SCENE_TITLE,
    SCENE_LEVEL
} GameScene;
GameScene currentScene = SCENE_TITLE;

//Sizes
const int screenWidth = 800;
const int screenHeight = 450;

//Version data
float version = 1.0;
char *type = "ALPHA";

int txtsize(int length, int size) {
     return length * (size / 2);
}

int CenterText(int length, int size) {
    return (screenWidth / 2) - (txtsize(length, size) / 2) - size; 
}

int scene(GameScene new) {
    currentScene = new;
}

int button(int x, int y, int height, int width, char *text) {
    DrawRectangle(x, y, width, height, GRAY);
    DrawText(text, x + 20, y + 10, 20, WHITE);
    DrawRectangleLines(x, y, width, height, WHITE);
}

int main(void) {
    InitWindow(screenWidth, screenHeight, "Geometry Crays");


    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        switch (currentScene) {
            case SCENE_TITLE:
                if (IsKeyPressed(KEY_ENTER)) {
                    currentScene = SCENE_LEVEL;
                }
                break;

            case SCENE_LEVEL:
                if (IsKeyPressed(KEY_ESCAPE)) {
                    currentScene = SCENE_TITLE;
                }
                break;
        }

        BeginDrawing();
        ClearBackground(DARKBLUE);
        DrawText("V 1.0", 20, 20, 15, WHITE);
        DrawText(type, 20, 40, 15, WHITE);
        switch (currentScene) {
            case SCENE_TITLE:
                DrawText("Geometry Crays", CenterText(14, 30), 100, 30, WHITE);
                DrawText("A port of Geometry Rays & Extensions", CenterText(14, 10) - 100, 150, 15, WHITE);
                button(400 - 100, 180, 35, 180, "Play");
                button(400 - 100, 225, 35, 180, "Editor/Online");
                button(400 - 100, 270, 35, 180, "Extensions");
                break;
            
            case SCENE_LEVEL:
                DrawText("Level Scene - Press ESC to Return", 200, 200, 20, DARKGRAY);
                break;
        }

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
