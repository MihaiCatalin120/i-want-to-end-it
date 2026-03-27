#include "environment.h"
#include <stdbool.h>

#ifndef PLAYER_H
#define PLAYER_H

typedef struct Player {
  Vector2 position;
  Vector2 size;
  float speed;
  bool canJump;
} Player;

void UpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength,
                  float delta);

#endif
