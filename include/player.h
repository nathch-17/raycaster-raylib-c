#ifndef PLAYER_H
#define PLAYER_H

struct joueur {
  // Position sur le tableau en 2D
  float pos_x;
  float pos_y;
  // Vecteur de direction
  float dir_x;
  float dir_y;

  // Vitesse joueur déplacement
  float spd;

  char joueur;

  float rot_spd;

  // Angle du joueur
  float angle;
  float shoot_timer;
};

typedef struct joueur Player;
void init_player(Player *pl);
void shoot_player(Player *pl);
void move_player2(Player *pl);
#endif
