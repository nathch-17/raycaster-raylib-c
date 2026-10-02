#ifndef MAP_H
#define MAP_H

#include "player.h" // Nécessaire car print_grid utilise le type player*

#define MAX 8

extern int map[MAX][MAX]; // Le mot-clé "extern" permet aux autres fichiers de
                          // lire ta carte

void print_grid(int grid[MAX][MAX], player *pl);
void draw_grid(int grid[MAX][MAX]);
void generer_map();

#endif
