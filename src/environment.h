#include "raylib.h"

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

typedef struct EnvItem {
  Rectangle rect;
  int blocking;
  Color color;
} EnvItem;

#endif
