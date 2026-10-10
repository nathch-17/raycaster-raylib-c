#include "game.h"
#include "hud.h"
#include "player.h"
#include "raylib.h"
#include <stdlib.h>

int main() {

  InitWindow(SCREEN_W, SCREEN_H, "mini jeu - basic window");
  SetTargetFPS(60);

  Player pl;
  init_player(&pl);

  while (!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(BLACK);
    cast_rays(&pl);

    move_player2(&pl);

    draw_minimap(&pl);
    draw_crosshair();
    EndDrawing();
  }

  CloseWindow();
  return EXIT_SUCCESS;
}
