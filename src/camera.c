#include "camera.h"

void UpdateCameraCenter(Camera2D *camera, Player *player, float delta,
                        int width, int height) {
  camera->offset = (Vector2){width / 2.0f, height / 2.0f};
  camera->target = camera->offset;
}
