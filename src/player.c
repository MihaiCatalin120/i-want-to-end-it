#include "player.h"
#include "config.h"
#include "raylib.h"
#include "raymath.h"
#include <stdio.h>

void InitPlayer(Player *player) {
  player->position = (Vector2){400, 280};
  player->size = (Vector2){40.0f, 40.0f};
  player->speed = 0;
  player->health = 100.0f;
  player->canJump = false;
}

Color GetPlayerColor(Player *player) {
  Color result = GREEN;
  result.g = result.g - (100.0f - player->health) * 2.0f;
  result.r = result.r + (100.0f - player->health) * 2.0f;
  return result;
}

void CheckPlatformCollisions(Player *player, Platform *platforms,
                             int platformsLength, bool *hitObstacle,
                             float delta) {
  for (int i = 0; i < platformsLength; i++) {
    Platform *platform = platforms + i;
    Vector2 *p = &(player->position);
    if (platform->blocking && platform->rect.x <= p->x &&
        platform->rect.x + platform->rect.width >= p->x &&
        platform->rect.y >= p->y &&
        platform->rect.y <= p->y + player->speed * delta) {
      *hitObstacle = true;

      if (player->speed * delta > FALL_DAMAGE_THRESHOLD) {
        player->health -=
            (player->speed * delta - FALL_DAMAGE_THRESHOLD) * 10.0f;
        if (player->health < 0.0f)
          player->health = 0.0f;
      }

      player->speed = 0.0f;
      p->y = platform->rect.y;
      break;
    }
  }
}

void CheckSpikeCollisions(Player *player, Spike *spikes, int spikesLength,
                          float delta) {
  for (size_t i = 0; i < spikesLength; i++) {
    if (CheckCollisionPointTriangle(player->position, spikes[i].a, spikes[i].b,
                                    spikes[i].c)) {
      player->health = 0.0f;
      return;
    }
  }
}

void UpdatePlayer(Player *player, const Level *level, float delta) {
  if (player->health == 0.0f)
    return;

  if (IsKeyDown(KEY_LEFT))
    player->position.x -= PLAYER_HORIZONTAL_SPEED * delta;
  if (IsKeyDown(KEY_RIGHT))
    player->position.x += PLAYER_HORIZONTAL_SPEED * delta;
  if (IsKeyDown(KEY_SPACE) && player->canJump) {
    player->speed = -PLAYER_JUMP_SPEED;
    player->canJump = false;
  }

  player->position.x = Clamp(player->position.x, player->size.x / 2,
                             WINDOW_WIDTH - player->size.x / 2);

  bool hitObstacle = false;

  CheckPlatformCollisions(player, level->platforms, level->platformsLength,
                          &hitObstacle, delta);

  CheckSpikeCollisions(player, level->spikes, level->spikesLength, delta);

  if (!hitObstacle) {
    player->position.y += player->speed * delta;
    player->speed += GRAVITY * delta;
    player->canJump = false;
  } else
    player->canJump = true;
}
