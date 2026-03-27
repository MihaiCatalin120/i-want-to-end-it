#include "camera.h"
#include "config.h"

void InitCamera(Camera2D *camera) {
  Vector2 screenCenter = {WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f};
  camera->target = screenCenter;
  camera->offset = screenCenter;
  camera->rotation = 0.0f;
  camera->zoom = 1.0f;
}

void UpdateCameraCenter(Camera2D *camera, Player *player, float delta,
                        int width, int height) {
  camera->offset = (Vector2){width / 2.0f, height / 2.0f};
  camera->target = camera->offset;
}
