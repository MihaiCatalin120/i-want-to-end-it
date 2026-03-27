#include "player.h"
#include "config.h"
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

void CheckEnvironmentCollisions(Player *player, EnvItem *envItems,
                                int envItemsLength, bool *hitObstacle,
                                float delta) {
  for (int i = 0; i < envItemsLength; i++) {
    EnvItem *ei = envItems + i;
    Vector2 *p = &(player->position);
    if (ei->blocking && ei->rect.x <= p->x &&
        ei->rect.x + ei->rect.width >= p->x && ei->rect.y >= p->y &&
        ei->rect.y <= p->y + player->speed * delta) {
      *hitObstacle = true;
      if (player->speed * delta > 0)
        printf("HIT OBSTACLE with %f speed\n", player->speed * delta);
      if (player->speed * delta > FALL_DAMAGE_THRESHOLD) {
        player->health -=
            (player->speed * delta - FALL_DAMAGE_THRESHOLD) * 10.0f;
        if (player->health < 0.0f)
          player->health = 0.0f;
        printf("Owie: hp is now %f\n", player->health);
      }
      player->speed = 0.0f;
      p->y = ei->rect.y;
      break;
    }
  }
}

void UpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength,
                  float delta) {
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

  CheckEnvironmentCollisions(player, envItems, envItemsLength, &hitObstacle,
                             delta);

  if (!hitObstacle) {
    player->position.y += player->speed * delta;
    player->speed += GRAVITY * delta;
    player->canJump = false;
  } else
    player->canJump = true;
}
