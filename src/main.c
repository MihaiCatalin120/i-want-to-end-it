#include "raylib.h"

#include "camera.h"
#include "config.h"
#include "player.h"

#include <stdio.h>

int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_TITLE);
  InitAudioDevice();
  const char *appPath = GetApplicationDirectory();

  Player player = {0};
  player.position = (Vector2){400, 280};
  player.speed = 0;
  player.canJump = false;
  EnvItem envItems[] = {{{0, 400, 800, 200}, 1, GRAY},
                        {{200, 200, 400, 10}, 1, GRAY},
                        {{100, 300, 100, 10}, 1, GRAY},
                        {{600, 300, 100, 10}, 1, GRAY}};

  int envItemsLength = sizeof(envItems) / sizeof(envItems[0]);

  Camera2D camera = {0};
  Vector2 screenCenter = {WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f};
  camera.target = screenCenter;
  camera.offset = screenCenter;
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;

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

    Rectangle playerRect = {player.position.x - 20, player.position.y - 40,
                            40.0f, 40.0f};
    DrawRectangleRec(playerRect, RED);

    EndMode2D();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
