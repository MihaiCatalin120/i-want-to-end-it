#include "raylib.h"

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

typedef struct Platform {
  Rectangle rect;
  bool blocking;
  Color color;
} Platform;

typedef struct Spike {
  Vector2 a;
  Vector2 b;
  Vector2 c;
} Spike;

typedef struct Level {
  Vector2 playerStartPos;
  Platform *platforms;
  int platformsLength;
  Spike *spikes;
  int spikesLength;
} Level;

extern const Level levels[];
#endif
