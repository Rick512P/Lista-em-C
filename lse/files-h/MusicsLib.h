/*
Author: Érick Santos Matos
Id: 2310100966
Date: 07/05/2024
*/

#ifndef BIBLIOTECAS_H
#define BIBLIOTECAS_H

//bibliotecas já existentes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

//definição das estruturas
typedef struct node Node;
typedef struct musica Musica;

//criação das estruturas
struct musica{
    char title[256];
    char artist[256];
    char letter[256];
    int code;
    int views;
};

struct node{
    Musica *info;
    Node *next;
};

//definição da lista
typedef struct{
    int size;
    Node *first;
}Desc;

// definição das funções
Desc* InitDesc();
Node* NiwMusic();
void InsertMusic(Desc *desc, Node *MusicItem, int position);
Node* Musics(Desc *desc);
Node* RemoveMusic(Desc *desc, int position);
void SearchMusic(Desc *desc, int code);
void SearchAllMusics(Desc *desc);
void PrintMusic(Desc *desc);
void FreeMem(Desc *desc);

#endif