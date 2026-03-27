#include "raylib.h"

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

typedef struct EnvItem {
  Rectangle rect;
  bool blocking;
  Color color;
} EnvItem;

typedef struct Level {
  Vector2 playerStartPos;
  EnvItem *envItems;
  int envItemsLength;
} Level;

extern const Level levels[];
#endif
