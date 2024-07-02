/*
  Autor: Érick Santos Matos
  Matrícula: 2310100966
  Atividade Semi-presencial 5 - Fila Músicas
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct music Musica;
typedef struct nodo Nodo;
typedef struct desc Desc;

struct music{
    char titulo[256];
    char artista[256];
    char letra[256];
    int codigo;
    int execucoes;
};

struct nodo{
    Nodo *prox;
    Musica *info;
    Nodo *ante;
};

struct desc{
    Nodo *head;
    Nodo *tail;
    int tamanho;
};


Desc * criaDesc();
Nodo * criaNodo();
Musica * preencheElemento();
void ENQUEUE(Desc *descritor, Nodo *elemento, Musica *musica);
Nodo * DEQUEUE(Desc *descritor);
void ShowQueue(Desc *descritor);
void limpaQueue(Desc *descritor);
