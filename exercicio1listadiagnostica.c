#include <stdio.h>
#include <stdlib.h>

/*Exerc´ıcio 1. [Ponteiros] Um ponteiro pode ser usado para dizer a uma fun¸c˜ao onde ela deve depositar
o resultado de seus c´alculos. Escreva uma fun¸c˜ao que converta uma quantidade de minutos na nota¸c˜ao
horas/minutos. A fun¸c˜ao recebe como parˆametro:
• um n´umero inteiro (totalMinutos); e
• os endere¸cos de duas vari´aveis inteiras, horas e minutos.
A fun¸c˜ao deve ent˜ao atribuir valores `as vari´aveis passadas por referˆencia, de modo que os valores atribu´ıdos
respeitem as seguintes condi¸c˜oes:
minutos < 60
60 ∗ horas + minutos = totalMinutos
Escreva tamb´em a fun¸c˜ao principal (main) que use a fun¸c˜ao desenvolvida.*/

void totalminutos(int min,int* pmin,int* phoras) {//ponteiro agora tem o  endereço de memoria da variavel min e horas.

    (*phoras) = (*pmin)/60; //resultado da hora
    (*pmin) = min%60;


}

int main() {
    int pmin;
    int phoras;
    int min,horas=0;

    printf("digite o numero de minutos:");
    scanf("%d",&min);
    totalminutos(min,&min,&horas);
    printf("%d:%d\n",horas,min );

  return 0;
}
