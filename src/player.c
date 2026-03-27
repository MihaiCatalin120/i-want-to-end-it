#include "player.h"
#include "config.h"
#include "raymath.h"
#include <stdio.h>

void UpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength,
                  float delta) {
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
  for (int i = 0; i < envItemsLength; i++) {
    EnvItem *ei = envItems + i;
    Vector2 *p = &(player->position);
    if (ei->blocking && ei->rect.x <= p->x &&
        ei->rect.x + ei->rect.width >= p->x && ei->rect.y >= p->y &&
        ei->rect.y <= p->y + player->speed * delta) {
      hitObstacle = true;
      if (player->speed * delta > 0)
        printf("HIT OBSTACLE with %f speed\n", player->speed * delta);
      if (player->speed * delta > FALL_DAMAGE_THRESHOLD)
        printf("Owie\n");
      player->speed = 0.0f;
      p->y = ei->rect.y;
      break;
    }
  }

  if (!hitObstacle) {
    player->position.y += player->speed * delta;
    player->speed += GRAVITY * delta;
    player->canJump = false;
  } else
    player->canJump = true;
}
