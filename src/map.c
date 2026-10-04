#include "map.h"
#include <raylib.h>
#include <stdio.h>
#define MAX 8

int map[8][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 1},
                 {1, 0, 0, 1, 1, 0, 0, 1}, {1, 0, 0, 1, 1, 0, 0, 1},
                 {1, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 0, 1, 1, 1},
                 {1, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1}};
void draw_grid(int grid[MAX][MAX]) {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      if (grid[i][j] == 1) {
        DrawRectangle(j * 100, i * 100, 100, 100, BLACK);
      }
    }
  }
}

void generer_map() {

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      if (i == 0 || j == 0 || i == MAX - 1 || j == MAX - 1) {
        map[i][j] = 1;
      } else {
        map[i][j] = 0;
      }
    }
  }
}
void print_grid(int grid[MAX][MAX], player *pl) {
  int row = MAX;
  int col = MAX;

  for (int i = 0; i < row; i++) {
    printf("[");
    for (int j = 0; j < col; j++) {
      if (pl->pos_x == j && pl->pos_y == i) {
        printf(" %3c ", pl->joueur);
      } else {
        printf(" %3d ", grid[i][j]);
      }
    }
    printf("]\n");
  }
}
