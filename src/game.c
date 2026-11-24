#include "game.h"
#include "hud.h"
#include "player.h"
#include "raylib.h"
#include <stdlib.h>

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

static Player pl;

void UpdateDrawFrame(void) {
  BeginDrawing();
  ClearBackground(BLACK);
  cast_rays(&pl);
  move_player2(&pl);
  DrawHud(&pl);
  EndDrawing();
}

int main(void) {

  InitWindow(SCREEN_W, SCREEN_H, "mini jeu - basic window");
  init_player(&pl);

#if defined(PLATFORM_WEB)
  /* 0 = laisse la navigauteur gérer les fps
   * 1 = simule boucle infinie
   */

  emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    UpdateDrawFrame();
  }
#endif

  CloseWindow();
  return EXIT_SUCCESS;
}
