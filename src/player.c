#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "player.h"
#include "raylib.h"
#include "map.h"
void move_player2(player* pl){

  int target_y;
  int target_x;
  
  float step_x = pl->spd*pl->dir_x;
  float step_y = pl->spd*pl->dir_y;

  
  float hitbox_x = 0.5f*pl->dir_x;
  float hitbox_y = 0.5f*pl->dir_y;
  
if (IsKeyDown(KEY_W)){

  target_y = (int)(pl->pos_y + step_y + hitbox_y);
  target_x = (int)(pl->pos_x + step_x + hitbox_x);
    
  if (map[(int)pl->pos_y][target_x] == 0) {
    pl->pos_x += step_x;
  }
  if (map[target_y][(int)pl->pos_x] == 0) {
    pl->pos_y += step_y;
  }

  
}
  if(IsKeyDown(KEY_S)){

    target_y = (int)(pl->pos_y - step_y - hitbox_y);
    target_x = (int)(pl->pos_x - step_x - hitbox_x);

    if (map[(int)pl->pos_y][target_x] == 0) {
      pl->pos_x -= step_x;
    }
    if (map[target_y][(int)pl->pos_x] == 0) {
      pl->pos_y -= step_y;
    }


  }

  if(IsKeyDown(KEY_A)){
    /*stockage ancienne variable de direction pour les deux axes*/
    float old_dir_x = pl->dir_x;
    float old_dir_y = pl->dir_y;
    /*application de la formule*/
    pl->dir_x = old_dir_x*cos(pl->rot_spd)-old_dir_y*sin(pl->rot_spd);
    pl->dir_y = old_dir_x*sin(pl->rot_spd)+old_dir_y*cos(pl->rot_spd);
  }
  if(IsKeyDown(KEY_D)){
    float old_dir_x = pl->dir_x;
    float old_dir_y = pl->dir_y;
    
    pl->dir_x = old_dir_x*cos(-pl->rot_spd)-old_dir_y*sin(-pl->rot_spd);
    pl->dir_y = old_dir_x*sin(-pl->rot_spd)+old_dir_y*cos(-pl->rot_spd);
  }
}

void draw_player(player* pl){
  float taille = 0.4f;
  float largeur = 0.3f;
  Vector2 v1;
  Vector2 v2;
  Vector2 v3;

  float perp_x = - pl->dir_y;
  float perp_y = pl->dir_x;

  v1.x =( pl->pos_x + taille * pl->dir_x)*100;
  v1.y = (pl->pos_y + taille * pl->dir_y)*100;
  
  v2.x = (pl->pos_x - (taille * pl->dir_x) + (largeur * perp_x))*100;
  v2.y = (pl->pos_y - (taille * pl->dir_y) + (largeur * perp_y))*100;

  v3.x = (pl->pos_x - (taille * pl->dir_x) - (largeur * perp_x))*100;
  v3.y = (pl->pos_y - (taille * pl->dir_y) - (largeur * perp_y))*100;


  DrawTriangle(v1,v3,v2,RED);



}
