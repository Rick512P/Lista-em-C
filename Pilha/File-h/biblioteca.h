/*
  Autor: Érick Santos Matos
  Matrícula: 2310100966
  Atividade Semi-presencial 4 - Pilha Músicas
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
};

struct desc{
    Nodo *pilha;
    int tamanho;
};


Desc * criaDesc();
Nodo * criaNodo();
Musica * preencheElemento();
void inserePilha(Desc *descritor, Nodo *elemento, Musica *musica);
Nodo * POP(Desc *descritor);
void TOP(Desc *pilha);
void ImprimirPIlha(Desc *descritor);
void removeElemento(Desc *descritor);
void limpaPilha(Desc *descritor);
