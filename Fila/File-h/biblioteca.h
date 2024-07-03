/*
  Autor: Érick Santos Matos
  Matrícula: 2310100966
  Atividade Semi-presencial 5 - Fila Músicas
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct musicfila MusicaFIla;
typedef struct nodofila NodoFila;
typedef struct descfila DescFila;

struct musicfila{
    char titulo[256];
    char artista[256];
    char letra[256];
    int codigo;
    int execucoes;
};

struct nodofila{
    NodoFila *prox;
    MusicaFIla *info;
    NodoFila *ante;
};

struct descfila{
    NodoFila *head;
    NodoFila *tail;
    int tamanho;
};


DescFila * criaDescFila();
NodoFila * criaNodoFila();
MusicaFIla * preencheElemento();
void ENQUEUE(DescFila *descritor, NodoFila *elemento, MusicaFIla *MusicaFIla);
NodoFila * DEQUEUE(DescFila *descritor);
void ShowQueue(DescFila *descritor);
void limpaQueue(DescFila *descritor);
