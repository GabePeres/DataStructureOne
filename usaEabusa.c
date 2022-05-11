#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// nome, sexo (m ou f), idade, peso, altura, e telefone para contato.
// Lista Duplamente Encadeada (TAD)
typedef struct NoLista* PtrNoLista ;

typedef struct NoLista{

  int valor;
  char nome;
  char sexo;
  int idade;
  float peso;
  float altura;
  char telefone;
  PtrNoLista prox;
  PtrNoLista anterior;

}NoLista;

typedef struct{

  PtrNoLista inicio;
  int quantidade;

}ListaDupla;


// inicia uma lista vazia.
void IniciaLista (ListaDupla *list){

  PtrNoLista sentinela = malloc(sizeof(NoLista));

  sentinela->valor =-1;
  sentinela->Proximo = sentinela;
  sentinela->anterior = sentinela;

  list->inicio = sentinela;
  list->quantidade = 0;
}

//verifica se o inicio aponta pŕa NULL e retorna true or false.
bool VerificarVazia(ListaDupla *list){

  return (list->inicio == NULL);

}

//retorna a variavel quantidade.
int TamanhoListaDupla (ListaDupla *list){

  return (list->quantidade);
}

void ImprimirListaDupla(ListaDupla *list){

  PtrNoLista aux;

  printf("lista [");

  for (aux = list->inicio; aux !=  NULL; aux = aux->prox) {
    printf(" %d,",aux->valor);
  }
  printf("]\n");

}

void insereArq() {

}

 void InserirListaDupla (ListaDupla *list, int num){

   bool confere;
   PtrNoLista novo;

   //   caso 1: lista vazia
   //     - Proximo do Novo é NULL
   //     - Anterior do Novo é NULL
   //     - Inicio aponta para o Novo
   //
   //   caso 2: menor que o primeiro elemento
   //     - Proximo do Novo recebe Inicio
   //     - Anterior do Inicio recebe novo
   //     - Anterior do Novo recebe NULL
   //     - Inicio recebe Novo


   novo = malloc(sizeof(NoLista));

   novo->valor = num;

   confere = VerificarVazia(&list);

    if (confere == 1 || novo->valor < list->inicio->valor) {

      novo->prox = list->inicio;

    } else {

      //
      //   caso 3: percorrer a lista (meio, final)
      //     - Encontrar o ponto de inserção (Aux)
      //     - Proximo do Novo recebe prox Aux (NULL | ou não NULL)
      //     - Se o Proximo do Aux != NULL
      //           - Anterior do Proximo do Aux recebe novo
      //     - Anterior do Novo recebe Aux
      //     - Proximo do Aux recebe Novo

      PtrNoLista aux = list->inicio;

    while (aux->prox != NULL && aux->prox->valor <= num) {
      aux = aux->prox;
    }
    novo->prox = aux->prox;
    aux->prox = novo;

    }

  list->quantidade++;
}


int main(int argc, char const *argv[]) {
  ListaDupla l;


  // checar erros de abertura de arquivo
  if (argc > 3 ||argc < 3 ) {
    printf("Error to try read\n");
    return 1;//finaliza programa
  }//if testa quantidade dos arquivos

  FILE* entrada = fopen(argv[1], "r");
  FILE* saida   = fopen(argv[2], "w");

  if(entrada == NULL || saida == NULL) {
     printf("Erro: algum dos arquivos não pode ser criado corretamente\n");
     return 0;
  }


  IniciaLista(&l);

  char ch;
  while(!feof(entrada)) {
    // obtendo caracter do arquivo de entrada
    ch = fgetc(entrada);
    // escrever esse caracter no arquivo de saida (que vai ser criado)
    fprintf(saida, "%c", ch);
  }

// ate o fim do arquivo
//  ate o fim do da linha
//    ate a virgula
//    se for caracter = novo "cliente", se não é informação do mesmo
//      str tok
//        usar fgets para pegar a linha inteira.
  inserirListaDupla(&l);
  ImprimirListaDupla(&l);

//  inserirListaDupla(&l,valor)
  printf("foi  \n\n");

  fclose(entrada);
  fclose(saida);
  return 0;
}
