#include "raylib.h"

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

typedef struct EnvItem {
  Rectangle rect;
  bool blocking;
  Color color;
} EnvItem;

#endif
