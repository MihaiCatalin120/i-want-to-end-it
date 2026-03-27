#include "raylib.h"

#include "camera.h"
#include "config.h"
#include "environment.h"
#include "player.h"
#include "ui.h"

#include <stdio.h>

int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_TITLE);
  InitAudioDevice();
  const char *appPath = GetApplicationDirectory();

  size_t currentLevel = 0;
  Player player = {0};
  InitPlayer(&player);

  player.position = levels[currentLevel].playerStartPos;
  EnvItem *envItems = levels[currentLevel].envItems;
  int envItemsLength = levels[currentLevel].envItemsLength;

  Camera2D camera = {0};
  InitCamera(&camera);

  SetTargetFPS(60);
  while (!WindowShouldClose()) {

    float deltaTime = GetFrameTime();

    UpdatePlayer(&player, envItems, envItemsLength, deltaTime);

    if (player.health == 0.0f) {
      if (IsKeyPressed(KEY_ENTER)) {
        currentLevel++;
        player.health = 100.0f;

        // TODO: magic number - number of levels
        currentLevel = currentLevel % 2;

        player.position = levels[currentLevel].playerStartPos;
        envItems = levels[currentLevel].envItems;
        envItemsLength = levels[currentLevel].envItemsLength;
      }
    }

    BeginDrawing();
    ClearBackground(LIGHTGRAY);

    BeginMode2D(camera);

    for (int i = 0; i < envItemsLength; i++)
      DrawRectangleRec(envItems[i].rect, envItems[i].color);

    Rectangle playerRect = {player.position.x - player.size.x / 2,
                            player.position.y - player.size.y, player.size.x,
                            player.size.y};
    DrawRectangleRec(playerRect, GetPlayerColor(&player));

    if (player.health == 0.0f) {
      DrawEndRoundBox("You died", "Press ENTER to advance", 64, 12, GREEN);
    }

    EndMode2D();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
