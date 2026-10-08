#include "player.h"
#include <raylib.h>
#ifndef GAME_H
#define GAME_H

/* ─── Configuration ──────────────────────────────────────────────────────────
 */
#define SCREEN_W 1920
#define SCREEN_H 1200

/*-------RAYCASTER-----------*/

void cast_rays(Player *pl);
#endif
