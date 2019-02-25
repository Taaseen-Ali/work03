#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;
  struct matrix *edges, *new_m, *m1, *m2;

  m1 = new_matrix(4,4);
  m2 = new_matrix(4,2);
  
  printf("m1=\n");
  print_matrix(m1);

  printf("m2=\n");
  print_matrix(m2);

  printf("populating matrices using add_edge\n");
  add_edge(m1, 1,1,3,5,2,6);
  add_edge(m1, 3,3,5,9,9,1);
  add_edge(m1, 2,1,1,0,8,7);
  add_edge(m1, 3,4,6,5,8,8);

  printf("m1=\n");
  print_matrix(m1);

  add_edge(m2, 2,1,1,2,1,2);

  printf("m2=\n");
  print_matrix(m2);

  printf("matrix mult test\n");
  matrix_mult(m2,m1);
  printf("m1=\n");
  print_matrix(m1);

  printf("ident test\n");
  struct matrix *m3 = new_matrix(4,4);
  ident(m3);
  printf("m3=\n");
  print_matrix(m3);
  
  new_m = new_matrix(4, 2);

  add_edge(new_m, 0,0,0,5,5,5); 
  add_edge(new_m, 10,10,10,50,50,50); 
  add_edge(new_m, 100,100,100,500,500,500); 
  add_edge(new_m, 500,500,100,300,20,200); 

  draw_lines(new_m, s, c);
  save_ppm(s,"matrix.ppm");
  save_extension(s, "matrix.png");
  display(s);
}  
