/*
  Autor: Érick Santos Matos
  Matrícula: 2310100966
  Atividade Semi-presencial 4 - Pilha Músicas
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct musicpIlha MusicaPIlha;
typedef struct nodopIlha NodoPIlha;
typedef struct descpIlha DescPIlha;

struct musicpIlha{
    char titulo[256];
    char artista[256];
    char letra[256];
    int codigo;
    int execucoes;
};

struct nodopIlha{
    NodoPIlha *prox;
    MusicaPIlha *info;
};

struct descpIlha{
    NodoPIlha *pilha;
    int tamanho;
};


DescPIlha * criaDescPIlha();
NodoPIlha * criaNodoPIlha();
MusicaPIlha * preencheElemento();
void inserePilha(DescPIlha *descritor, NodoPIlha *elemento, MusicaPIlha *musica);
NodoPIlha * POP(DescPIlha *descritor);
void TOP(DescPIlha *pilha);
void ImprimirPIlha(DescPIlha *descritor);
void removeElemento(DescPIlha *descritor);
void limpaPilha(DescPIlha *descritor);
