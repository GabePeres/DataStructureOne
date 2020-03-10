#include <stdlib.h>
#include <stdio.h>

/*Exercício 3. [Recursão] Escreva uma função recursiva para calcular o valor de um número inteiro de base
x elevada a um expoente inteiro y.*/


int recursiva(int x, int y) {
  int mult;
  if (y==0) {
    return mult * 1;
  }else{

    mult = recursiva(x*x,y-1);
  }
}

int main() {

  int x,y,cont;

  printf("digite o valor da base e em seguida o valor do expoente:");
  scanf("%d",&x );
  scanf("%d",&y );

  cont = recursiva(x,y);

  printf("o numero elevado e: %d\n",cont);


  return 0;
}
