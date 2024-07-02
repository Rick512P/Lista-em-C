#include "../files-h/MusicsLib.h"

Desc* InitDesc(){//inicializa a lista, fazendo a alocação da memória para o descritor
    Desc *desc = (Desc*)malloc(sizeof(Desc));
    desc->first = NULL;//aponta para NULL
    desc->size = 0;//define o tamanho como 0
    return desc;
}