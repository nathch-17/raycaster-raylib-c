#include "game.h"
#include "map.h"
#include "player.h"
#include "raylib.h"
#include <math.h>

void cast_rays(player *pl) {

  float angle_step = PI / 3 / 800;

  float start_angle = pl->angle - PI / 6;

  float ray_angle;

  float ray_dir_x;
  float ray_dir_y;

  float wall_height;

  float dx;
  float dy;
  float ray_x = pl->pos_x;
  float ray_y = pl->pos_y;
  float distance_mur;
  for (int i = 0; i < 800; i++) {

    ray_angle = start_angle + i * angle_step;

    ray_dir_x = cos(ray_angle);

    ray_dir_y = sin(ray_angle);
  }

  while (map[(int)ray_y][(int)ray_x] == 0) {

    ray_x += ray_dir_x * 0.05f;
    ray_y += ray_dir_y * 0.05f;
  }

  dx = ray_x - pl->pos_x;
  dy = ray_y - pl->pos_y;
  distance_mur = sqrt(pow(dx, 2) + pow(dy, 2));

  distance_mur = distance_mur * cos(pl->angle - ray_angle);
  wall_height = SCREEN_H / distance_mur;
}
