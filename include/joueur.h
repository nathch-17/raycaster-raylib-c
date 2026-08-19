#include <stdio.h>
#include <stdlib.h>

struct joueur {
  //Position sur le tableau en 2D
  float pos_x;
  float pos_y;
// Vecteur de direction 
  float dir_x;
  float dir_y;

  //Vitesse joueur déplacement
  float spd;

  char joueur;
  
  float rot_spd;
};

typedef struct joueur player;


