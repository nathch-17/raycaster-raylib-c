#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "player.h"
#include <math.h>
#include "map.h"

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
        draw_player(&pl);
      
        
        move_player2(&pl); 
      
      EndDrawing();
    
   
    
    
  }



 

  CloseWindow();
  return EXIT_SUCCESS;
}
