#include "player.h"

#ifndef CAMERA_H
#define CAMERA_H

void InitCamera(Camera2D *camera);

void UpdateCameraCenter(Camera2D *camera, Player *player, float delta,
                        int width, int height);

#endif
