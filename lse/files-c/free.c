#include "../files-h/MusicsLib.h"


void FreeMem(Desc *desc){// libera alocação de memória referente aos elementos da lista
    Node *auxiliary = desc->first;
    Node *previous;
    while (auxiliary->next != NULL){
        previous = auxiliary;
        auxiliary = auxiliary->next;
        free(previous);//remove a lista desde o primeiro elemento, usando o aux como guia
    }
    free(auxiliary);
    desc->size = 0;
    desc->first = NULL;
}