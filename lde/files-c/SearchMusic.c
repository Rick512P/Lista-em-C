#include "../files-h/MusicsLib.h"

void SearchMusic(Desc *desc, int code){// imprime um música em específico
    Node *auxiliary = desc->first;
    while (auxiliary->info->code != code){//move o ponteiro para a música com o ID recebido
        auxiliary = auxiliary->next;
        if(auxiliary == NULL){// verifica a existencia do código(ID) fornecido
            fprintf(stderr, "=== Codigo Inexistente! ===\n=== Voltando ao Menu! ===");
            sleep(1);
            system("clear");
            return;
        }
    }
    printf("\n|->\tTítulo: %s\n", auxiliary->info->title);
    printf("|->\tLetra: %s\n", auxiliary->info->letter);
    printf("|->\tArtista: %s\n", auxiliary->info->artist);
    printf("|->\tCódigo(ID): %d\n", auxiliary->info->code);
    printf("|->\tVizualizações: %d\n\n", auxiliary->info->views);
}

void SearchAllMusics(Desc *desc){ // imprime todas as músicas (com detalhes) da lista e incremente as views
    Node *auxiliary = desc->first;
    while (auxiliary != NULL){
        auxiliary->info->views++;
        printf("\n|->\tTítulo: %s\n", auxiliary->info->title);
        printf("|->\tLetra: %s\n", auxiliary->info->letter);
        printf("|->\tArtista: %s\n", auxiliary->info->artist);
        printf("|->\tCódigo(ID): %d\n", auxiliary->info->code);
        printf("|->\tVizualizações: %d\n\n", auxiliary->info->views);
        auxiliary = auxiliary->next;        
    }
}