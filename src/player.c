#include "player.h"
#include "map.h"
#include "raylib.h"
#include <math.h>

void move_player2(player *pl) {

  int target_y;
  int target_x;

  float step_x = pl->spd * pl->dir_x;
  float step_y = pl->spd * pl->dir_y;

  float hitbox_x = 0.5f * pl->dir_x;
  float hitbox_y = 0.5f * pl->dir_y;

  if (IsKeyDown(KEY_W)) {

    target_y = (int)(pl->pos_y + step_y + hitbox_y);
    target_x = (int)(pl->pos_x + step_x + hitbox_x);

    /*verfier les collisions sur l'axe x et y*/
    if (map[(int)pl->pos_y][target_x] == 0) {
      pl->pos_x += step_x;
    }
    if (map[target_y][(int)pl->pos_x] == 0) {
      pl->pos_y += step_y;
    }
  }
  if (IsKeyDown(KEY_S)) {

    target_y = (int)(pl->pos_y - step_y - hitbox_y);
    target_x = (int)(pl->pos_x - step_x - hitbox_x);

    /*Vérifier les collisions sur l'axe x et y*/
    if (map[(int)pl->pos_y][target_x] == 0) {
      pl->pos_x -= step_x;
    }
    if (map[target_y][(int)pl->pos_x] == 0) {
      pl->pos_y -= step_y;
    }
  }

  if (IsKeyDown(KEY_A)) {
    pl->angle -= pl->rot_spd;
  }
  if (IsKeyDown(KEY_D)) {
    pl->angle += pl->rot_spd;
  }
  // Mise à jour de la direction basée uniquement sur le nouvel angle
  pl->dir_x = cos(pl->angle);
  pl->dir_y = sin(pl->angle);
}

void draw_player(player *pl) {
  float taille = 0.4f;
  float largeur = 0.3f;
  Vector2 v1;
  Vector2 v2;
  Vector2 v3;

  float perp_x = -pl->dir_y;
  float perp_y = pl->dir_x;

  v1.x = (pl->pos_x + taille * pl->dir_x) * 100;
  v1.y = (pl->pos_y + taille * pl->dir_y) * 100;

  v2.x = (pl->pos_x - (taille * pl->dir_x) + (largeur * perp_x)) * 100;
  v2.y = (pl->pos_y - (taille * pl->dir_y) + (largeur * perp_y)) * 100;

  v3.x = (pl->pos_x - (taille * pl->dir_x) - (largeur * perp_x)) * 100;
  v3.y = (pl->pos_y - (taille * pl->dir_y) - (largeur * perp_y)) * 100;

  DrawTriangle(v1, v3, v2, RED);
}
