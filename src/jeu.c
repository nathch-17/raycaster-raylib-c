#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "joueur.h"

#define MAX 8


int map[MAX][MAX];


void print_grid(int grid[MAX][MAX],player* pl){
  int row = MAX;
  int col = MAX;
  


  for (int i = 0;i<row ;i++){
    printf("[");
    for (int j = 0;j<col;j++) {
     if(pl->pos_x == j && pl->pos_y == i){
       printf(" %3c ",pl->joueur);
     }
      else{printf(" %3d ", grid[i][j]);}
    }
    printf("]\n");
  } 
 }



void generer_map(){

  for (int i =0;i< 8;i++) {
    for(int j =0; j< 8;j++){
      if(i == 0 || j == 0 || i == 7 || j == 7){
        map[i][j] = 1;
      }
      else{
        map[i][j] = 0;
      }
    }
  }
}

void move_player(char key,player* pl){
  switch (key) {
    case 's':
      if(map[pl->pos_y + 1][pl->pos_x] == 0){
      pl->pos_y ++;}
      break;
    case 'q':
      if(map[pl->pos_y][pl->pos_x - 1] == 0) {pl->pos_x --;}
      break;
    case 'z':
      if(map[pl->pos_y - 1][pl-> pos_x] == 0)
      {pl->pos_y --;}
      break;
    case 'd':
      if(map[pl->pos_y][pl->pos_x + 1] == 0){ 
        pl->pos_x ++;}
      break;
  }

}
int main()
{
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth,screenHeight,"mini jeu - basic window");
  SetTargetFPS(60);
  

  char key;

  player pl;
  pl.joueur = 'P';
  pl.pos_x = 3;
  pl.pos_y = 3;


  while (true) {
    generer_map();
    print_grid(map,&pl);
    scanf(" %c",&key);
    move_player(key,&pl); 
    
    
  }

  print_grid(map,&pl);
  printf("\n");
  generer_map();
  print_grid(map,&pl);

  CloseWindow();
  return EXIT_SUCCESS;
}
