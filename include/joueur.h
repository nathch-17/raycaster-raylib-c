#include <stdio.h>
#include <stdlib.h>

struct joueur {
  int pos_x;
  int pos_y;
  char joueur;

};

enum MoveState {
  MOVE_UP,
  MOVE_DOWN,
  MOVE_LEFT,
  MOVE_RIGTH,
  MOVE_NONE
}MoveState;

typedef enum MoveState move;
typedef struct joueur player;


