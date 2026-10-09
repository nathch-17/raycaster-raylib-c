#ifndef MAP_H
#define MAP_H
#include "player.h"
#define MAP_HEIGHT 20
#define MAP_WIDTH 20
#define TILE_SIZE 8
extern int map[MAP_HEIGHT][MAP_WIDTH]; // Le mot-clé "extern" permet aux autres
                                       // fichiers de lire ta carte

void draw_grid(int grid[MAP_HEIGHT][MAP_WIDTH]);
void draw_minimap(Player *pl);
void generer_map();

#endif
