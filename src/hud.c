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
/*draw weapon à remplacer plus tard*/
void draw_weapon(Player *pl) {
  int screenW = GetScreenWidth();
  int screenH = GetScreenHeight();

  // Dimensions de l'arme rudimentaire
  int weapon_w = 60;
  int weapon_h = 120;
  int weapon_x = (screenW / 2) - (weapon_w / 2);
  int weapon_y = screenH - weapon_h;

  // Si on est en train de tirer, on applique le recul et la flamme
  if (pl->shoot_timer > 0) {
    weapon_y += 20; // L'arme recule vers le bas

    // Flamme du canon (Muzzle flash)
    DrawCircle(screenW / 2, weapon_y - 20, 30, YELLOW);
    DrawCircle(screenW / 2, weapon_y - 20, 15, ORANGE);
  }

  // Le corps de l'arme
  DrawRectangle(weapon_x, weapon_y, weapon_w, weapon_h, DARKGRAY);
  DrawRectangle(weapon_x - 10, weapon_y + 40, weapon_w + 20, 20,
                GRAY); // Détail
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
