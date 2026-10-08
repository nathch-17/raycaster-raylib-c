#include "game.h"
#include "map.h"
#include "player.h"
#include "raylib.h"
#include <math.h>

void draw_wall_slice(float wall_height, int x) {
  int screenHeight = GetScreenHeight();

  int draw_start = (screenHeight / 2) - (wall_height / 2);
  int draw_end = (screenHeight / 2) + (wall_height / 2);

  if (draw_start < 0) {
    draw_start = 0;
  }
  if (draw_end >= screenHeight) {
    draw_end = screenHeight - 1;
  }

  DrawLine(x, draw_start, x, draw_end, BLUE);
}

void cast_rays(player *pl) {

  int screenWidth = GetScreenWidth();
  float angle_step = PI / 3 / screenWidth;

  float start_angle = pl->angle - PI / 6;

  float ray_angle, ray_dir_x, ray_dir_y;

  float wall_height, distance_mur, dx, dy;

  for (int i = 0; i < screenWidth; i++) {

    ray_angle = start_angle + i * angle_step;
    ray_dir_x = cos(ray_angle);
    ray_dir_y = sin(ray_angle);

    float ray_x = pl->pos_x;
    float ray_y = pl->pos_y;

    while (ray_x >= 0 && ray_x < MAP_WIDTH && ray_y >= 0 &&
           ray_y < MAP_HEIGHT && map[(int)ray_y][(int)ray_x] == 0) {
      ray_x += ray_dir_x * 0.05f;
      ray_y += ray_dir_y * 0.05f;
    }

    dx = ray_x - pl->pos_x;
    dy = ray_y - pl->pos_y;
    distance_mur = sqrt(pow(dx, 2) + pow(dy, 2));
    distance_mur = distance_mur * cos(pl->angle - ray_angle);

    wall_height = GetScreenHeight() / distance_mur;
    draw_wall_slice(wall_height, i);
  }
}
