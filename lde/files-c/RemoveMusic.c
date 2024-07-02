#include "../files-h/MusicsLib.h"


Node* RemoveMusic(Desc *desc, int Position){
    if (Position > desc->size || desc->size == 0){ //verifica a existencia da posição comparando com o tamanho da lista
        fprintf(stderr, "=+= Essa Posição não Existe! =+=\n");
        fprintf(stderr, "=+=   Retornando ao Menu!    =+=");
        sleep(1.3); //pausa cronometrada na execução do programa para efeitos vizuais
        system("clear"); //limpa a tela para efeitos vizuais
        return NULL;
    }
    
    if(Position == 0 && desc->size > 1){ // verifica se é o primeiro item da lista
        Node *auxiliary = desc->first;
        desc->first = desc->first->next;
        desc->size--;

        printf("\n ________________________________");
        printf("\n| Remoção Realizada com Sucesso! |\n");
        printf("\n ________________________________");
    }
    else if (desc->size == 1)
    {
        desc->first = NULL;
        desc->final = NULL;
        desc->size--;

        printf("\n ________________________________");
        printf("\n| Remoção Realizada com Sucesso! |\n");
        printf("\n ________________________________");
    }
    
    else { 
        Node *auxiliary = desc->first, *auxprev;
        int AuxPosition=0;
        if (Position <= desc->size/2){  // verifica se é mais vantajoso começar pelo início da lista
            while(auxiliary != NULL){ //compara o auxiliary com Nl para realizar o loop
                auxprev = auxiliary;
                auxiliary = auxiliary->next;
                AuxPosition++;
                if (AuxPosition == Position){ //compara a posição para remover da lista o elemento correto
                    auxiliary->next->previous = auxprev;
                    auxprev->next = auxiliary->next;
                    desc->size--;
                    printf("\n ________________________________");
                    printf("\n| Remoção Realizada com Sucesso! |\n");
                    printf("\n ________________________________");
                    return auxiliary;
                }
            }
        }

        else if (Position > desc->size/2){ // verifica se é mais vantajoso começar pelo fim da lista
            while(auxiliary != NULL){ //compara o auxiliary com Nl para realizar o loop
                auxprev = auxiliary;
                auxiliary = auxiliary->previous;
                AuxPosition--;
                if (AuxPosition == Position){ //compara a posição para remover da lista o elemento correto
                    auxprev->previous = auxiliary->previous;
                    auxiliary->previous->next = auxprev;
                    desc->size--;
                    printf("\n ________________________________");
                    printf("\n| Remoção Realizada com Sucesso! |\n");
                    printf("\n ________________________________");
                    return auxiliary;
                }
            }
        }
    }
}