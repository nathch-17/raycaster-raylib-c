#include "map.h"
#include "player.h"
#include <math.h>
#include <raylib.h>

#define MAP_HEIGHT 20
#define MAP_WIDTH 20
#define TILE_SIZE 8

int map[20][20] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
void draw_grid(int grid[MAP_HEIGHT][MAP_WIDTH]) {
  for (int i = 0; i < MAP_WIDTH; i++) {
    for (int j = 0; j < MAP_HEIGHT; j++) {
      if (grid[i][j] == 1) {
        DrawRectangle(j * 100, i * 100, 100, 100, BLACK);
      }
    }
  }
}

void draw_minimap(Player *pl) {
  /*dessin mur*/
  for (int i = 0; i < MAP_WIDTH; i++) {
    for (int j = 0; j < MAP_HEIGHT; j++) {
      if (map[j][i] == 1) {
        DrawRectangle(i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, TILE_SIZE, RED);
      }
      /*Dessin joueur*/
    }

    DrawCircle(pl->pos_x * TILE_SIZE, pl->pos_y * TILE_SIZE, 5.0, BROWN);

    /*Dessin rayon*/

    int screenWidth = GetScreenWidth();
    float angle_step = PI / 3 / screenWidth;

    float start_angle = pl->angle - PI / 6;

    float ray_angle, ray_dir_x, ray_dir_y;

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

      DrawLine(pl->pos_x * TILE_SIZE, pl->pos_y * TILE_SIZE, ray_x * TILE_SIZE,
               ray_y * TILE_SIZE, GREEN);
    }
  }
}
