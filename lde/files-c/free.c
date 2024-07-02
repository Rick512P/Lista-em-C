#include "../files-h/MusicsLib.h"


void FreeMem(Desc *desc){// libera alocação de memória referente aos elementos da lista
    Node *auxiliary = desc->first;
    while (auxiliary->next != NULL){
        if (desc->size == 1)
            free(auxiliary);
        else
            free(auxiliary->previous);//remove a lista desde o primeiro elemento, usando o aux como guia

        auxiliary = auxiliary->next;
    }
    free(auxiliary);
    desc->size = 0;
    desc->first = NULL;
    desc->final = desc->first;
}
