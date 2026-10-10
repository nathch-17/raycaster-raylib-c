#include "hud.h"
#include "map.h"
#include <math.h>
#include <raylib.h>

#define MAP_HEIGHT 20
#define MAP_WIDTH 20
#define TILE_SIZE 8

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

    for (int i = 0; i < screenWidth; i += 20) {

      ray_angle = start_angle + i * angle_step;
      ray_dir_x = cos(ray_angle);
      ray_dir_y = sin(ray_angle);

      float ray_x = pl->pos_x;
      float ray_y = pl->pos_y;

      while (map[(int)ray_y][(int)ray_x] == 0) {
        ray_x += ray_dir_x * 0.05f;
        ray_y += ray_dir_y * 0.05f;
      }

      DrawLine(pl->pos_x * TILE_SIZE, pl->pos_y * TILE_SIZE, ray_x * TILE_SIZE,
               ray_y * TILE_SIZE, GREEN);
    }
  }
}

void draw_crosshair() {
  int center_x = GetScreenWidth() / 2;
  int center_y = GetScreenHeight() / 2;
  int size = 10;          // La longueur des branches
  float thickness = 3.0f; // L'épaisseur de ton viseur

  // Ligne horizontale
  Vector2 start_h = {center_x - size, center_y};
  Vector2 end_h = {center_x + size, center_y};
  DrawLineEx(start_h, end_h, thickness, LIME);

  // Ligne verticale
  Vector2 start_v = {center_x, center_y - size};
  Vector2 end_v = {center_x, center_y + size};
  DrawLineEx(start_v, end_v, thickness, LIME);
}
