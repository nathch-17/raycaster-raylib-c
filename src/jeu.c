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

void draw_grid(int grid[MAX][MAX]){
  for (int i = 0;i<MAX;i++) {
    for (int j = 0 ;j < MAX;j++) {
      if(grid[i][j] == 1){
      DrawRectangle(j*100,i*100,100,100,BLACK);}
     

    }
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

void move_player(player* pl){
  
    if (IsKeyPressed(KEY_S)){
      if(map[pl->pos_y + 1][pl->pos_x] == 0){
      pl->pos_y +=1;}
    }
    
    if (IsKeyPressed(KEY_A)){
      if(map[pl->pos_y][pl->pos_x-1] == 0) {
        pl->pos_x -=1;}
    }
    
    if (IsKeyPressed(KEY_W)){
      if(map[pl->pos_y-1][pl-> pos_x] == 0){
        pl->pos_y -= 1;}
      }
  
    if(IsKeyPressed(KEY_D)){
      if(map[pl->pos_y][pl->pos_x + 1] == 0){ 
        pl->pos_x +=1;}
      }
}

int main()
{
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth,screenHeight,"mini jeu - basic window");
  SetTargetFPS(60);
  

  player pl;
  pl.joueur = 'P';
  pl.pos_x = 3;
  pl.pos_y = 3;
  generer_map();




  while (!WindowShouldClose()) 
    {
     
     
      
      BeginDrawing();
        ClearBackground(WHITE);
        draw_grid(map);
        DrawRectangle(pl.pos_x*100,pl.pos_y*100,100,100,RED);
        move_player(&pl); 
      
      EndDrawing();
    
   
    
    
  }



 

  CloseWindow();
  return EXIT_SUCCESS;
}
