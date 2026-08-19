#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "joueur.h"
#include <math.h>


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



void move_player2(player* pl){
  
  if (IsKeyPressed(KEY_W)){
    if(/*vérifier collisions*/
        map[(int)(pl->pos_y + pl->spd*pl->dir_y)][(int) (pl->pos_x + pl->spd*pl->dir_x)] == 0){
      pl->pos_x += pl->spd*pl->dir_x;
      pl->pos_y += pl->spd*pl->dir_y;
    }
  }
  if(IsKeyPressed(KEY_S)){
    if(/*vérifier collisions*/
        map[(int)(pl->pos_y - pl->spd*pl->dir_y)][(int)(pl->pos_x - pl->spd*pl->dir_x)] == 0 ){
    pl->pos_x -= pl->spd*pl->dir_x;
    pl->pos_y -= pl->spd*pl->dir_y;
    }
  }

  if(IsKeyPressed(KEY_A)){
    /*stockage ancienne variable de direction pour les deux axes*/
    float old_dir_x = pl->dir_x;
    float old_dir_y = pl->dir_y;
    /*application de la formule*/
    pl->dir_x = old_dir_x*cos(pl->rot_spd)-old_dir_y*sin(pl->rot_spd);
    pl->dir_y = old_dir_x*sin(pl->rot_spd)+old_dir_y*cos(pl->rot_spd);
  }
  if(IsKeyPressed(KEY_D)){
    float old_dir_x = pl->dir_x;
    float old_dir_y = pl->dir_y;
    
    pl->dir_x = old_dir_x*cos(-pl->rot_spd)-old_dir_y*sin(-pl->rot_spd);
    pl->dir_y = old_dir_x*sin(-pl->rot_spd)+old_dir_y*cos(-pl->rot_spd);

    
  }
}
int main(){
   
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth,screenHeight,"mini jeu - basic window");
  SetTargetFPS(60);
  

  player pl;
  pl.joueur = 'P';
  pl.pos_x = 3.5f;
  pl.pos_y = 3.5f;
  pl.dir_x = 1;
  pl.dir_y = 0;
  pl.spd = 0.1f;
  pl.rot_spd = 0.05f;

  generer_map();



  while (!WindowShouldClose()) 
    {
     
     
      
      BeginDrawing();
        ClearBackground(WHITE);
        draw_grid(map);
        DrawRectangle(pl.pos_x*100,pl.pos_y*100,100,100,RED);
        move_player2(&pl); 
      
      EndDrawing();
    
   
    
    
  }



 

  CloseWindow();
  return EXIT_SUCCESS;
}
