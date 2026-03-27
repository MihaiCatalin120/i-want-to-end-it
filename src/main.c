#include "raylib.h"

#include "camera.h"
#include "config.h"
#include "player.h"
#include "ui.h"

#include <stdio.h>

int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_TITLE);
  InitAudioDevice();
  const char *appPath = GetApplicationDirectory();

  Player player = {0};
  InitPlayer(&player);

  EnvItem envItems[] = {{{0, 400, 800, 200}, true, GRAY},
                        {{200, 200, 400, 10}, true, GRAY},
                        {{100, 300, 100, 10}, true, GRAY},
                        {{600, 300, 100, 10}, true, GRAY}};

  int envItemsLength = sizeof(envItems) / sizeof(envItems[0]);

  Camera2D camera = {0};
  InitCamera(&camera);

  SetTargetFPS(60);
  while (!WindowShouldClose()) {

    float deltaTime = GetFrameTime();

    UpdatePlayer(&player, envItems, envItemsLength, deltaTime);

    UpdateCameraCenter(&camera, &player, deltaTime, WINDOW_WIDTH,
                       WINDOW_HEIGHT);

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
