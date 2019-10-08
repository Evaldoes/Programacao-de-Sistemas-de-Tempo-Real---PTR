#include "simulation.h"
#include "matrix.h"
#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[]) {

  int time = 20;
  Matrix id = matrix_identity("identidade", 3, 3);

  Matrix position;
  Matrix speed;
  Matrix result;
  char path[100];

  strcpy(path,argv[1]);

  FILE* arquivo = fopen(path,"w+");

  for(double i=0; i < time; i+=0.1){
    
    position = getPosition(i, i-1);
    speed = getSpeed(i);
    result = simulate(i, getSpeed(i));

    matrix_print_file(position,arquivo);
    matrix_print_file(speed,arquivo);
    matrix_print_file(result,arquivo);
    
    fprintf(arquivo,"\n");
  }

  fclose(arquivo);

}
