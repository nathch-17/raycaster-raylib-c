#include "game.h"
#include "map.h"
#include "player.h"
#include "raylib.h"
#include <stdlib.h>

int main() {

  InitWindow(SCREEN_W, SCREEN_H, "mini jeu - basic window");
  SetTargetFPS(60);

  player pl;
  pl.joueur = 'P';
  pl.pos_x = 3.5f;
  pl.pos_y = 3.5f;
  pl.dir_x = 1;
  pl.dir_y = 0;
  pl.spd = 0.2f;
  pl.rot_spd = 0.05f;
  pl.angle = 0.0f;

  generer_map();

  while (!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(BLACK);
    cast_rays(&pl);

    move_player2(&pl);

    EndDrawing();
  }

  CloseWindow();
  return EXIT_SUCCESS;
}
