#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges, *new_m;
  
  edges = new_matrix(4, 4);
  new_m = new_matrix(4, 4);
  new_m->m[0][0] = 4;
  new_m->m[3][2] = 7;

  ident(edges);

  edges->m[0][0] = 2;
  matrix_mult(edges, new_m);

  print_matrix(edges);
  print_matrix(new_m);
  free_matrix( edges );
}  
