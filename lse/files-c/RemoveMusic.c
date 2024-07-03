#include "../files-h/MusicsLib.h"


Node* RemoveMusic(Desc *desc, int Position){
    if (Position > desc->size-1 || desc->size == 0){ //verifica a existencia da posição comparando com o tamanho da lista
        fprintf(stderr, "=+= Essa Posição não Existe! =+=\n");
        fprintf(stderr, "=+=   Retornando ao Menu!    =+=");
        sleep(1.3); //pausa cronometrada na execução do programa para efeitos vizuais
        system("clear"); //limpa a tela para efeitos vizuais
        return NULL;
    }
    
    if(Position == 0 && desc->size>1){ // verifica se é o primeiro item da lista
        desc->first = desc->first->next;
        desc->size--;
        printf("\n ________________________________");
        printf("\n| Remoção Realizada com Sucesso! |\n");
        printf("\n ________________________________");
    }
    else if(desc->size = 1){
        desc->first=NULL;
        desc->size--;
        printf("\n ________________________________");
        printf("\n| Remoção Realizada com Sucesso! |\n");
        printf("\n ________________________________");
    }
    else { 
        Node *auxiliary = desc->first, *previous;
        int AuxPosition=0;
        while(auxiliary != NULL){ //compara o auxiliary com Nl para realizaURL o loop
            previous = auxiliary;
            auxiliary = auxiliary->next;
            AuxPosition++;
            if (AuxPosition == Position){ //compara a posição para remover da lista o elemento correto
                previous->next = auxiliary->next;
                desc->size--;
                printf("\n ________________________________");
                printf("\n| Remoção Realizada com Sucesso! |\n");
                printf("\n ________________________________");
                return auxiliary;
            }
        }
        
    }
}