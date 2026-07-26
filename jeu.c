#include <stdio.h>
#include <stdlib.h>

#define MAX 8
int map[MAX][MAX];

int joueur_x = 3;
int joueur_y = 3;
char joueur = 'P';
void print_grid(int grid[MAX][MAX]){
  int row = MAX;
  int col = MAX;
  


  for (int i = 0;i<row ;i++){
    printf("[");
    for (int j = 0;j<col;j++) {
     if(joueur_x == j && joueur_y == i){
       printf(" %3c ",joueur);
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

void move_player(char key){
  switch (key) {
    case 's':
      joueur_y ++;
      break;
    case 'q':
      joueur_x --;
      break;
    case 'z':
      joueur_y --;
      break;
    case 'd': 
      joueur_x ++;
      break;
  }
}
int main(int argc, char *argv[])
{

  char key;

  while (true) {
    generer_map();
    print_grid(map);
    scanf(" %c",&key);
    move_player(key); 
    
    
  }

  print_grid(map);
  printf("\n");
  generer_map();
  print_grid(map);
  return EXIT_SUCCESS;
}
