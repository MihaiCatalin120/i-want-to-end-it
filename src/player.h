#include "environment.h"
#include <stdbool.h>

#ifndef PLAYER_H
#define PLAYER_H

typedef struct Player {
  Vector2 position;
  Vector2 size;
  float speed;
  float health;
  bool canJump;
} Player;

void InitPlayer(Player *player);

Color GetPlayerColor(Player *player);

void UpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength,
                  float delta);

#endif
