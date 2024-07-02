#include "../files-h/MusicsLib.h"

Node* Musics(Desc *desc){
    Node *MusicItem = (Node*)malloc(sizeof(Node)); //alocação de memória para a variável MusicItem
    setbuf(stdin, NULL);
    if (MusicItem == NULL) { //verifica o sucesso na alocação
        fprintf(stderr, "=+=                 Erro 001!                 =+=\n");
        fprintf(stderr, "=+= FALHA AO ALOCAR MEMÓRIA PARA O NOVO ITEM! =+=\n");
        fprintf(stderr, "=+=            Retornando ao Menu!            =+=\n");
        setbuf(stdin, NULL);
        return NULL;
    }
    Node *auxiliary;
    int verificacao = -1;
    MusicItem->info = (Musica*)malloc(sizeof(Musica)); //alocação de memória para a variável Musica
    if (MusicItem->info == NULL) { //verifica o sucesso na alocação
        fprintf(stderr, "=+=                  Erro 002!                  =+=\n");
        fprintf(stderr, "=+= FALHA AO ALOCAR MEMÓRIA PARA A NOVA MÚSICA! =+=\n");
        fprintf(stderr, "=+=             Retornando ao Menu!             =+=\n");
        setbuf(stdin, NULL);
        free(MusicItem);
        return NULL;
    }

    printf("\n _____________________________");
    printf("\n|Entre com o Título da Música |");
    printf("\n _____________________________");
    printf("\n--> ");
    scanf(" %255[^\n]", MusicItem->info->title);

    printf("\n ___________________________");
    printf("\n|Entre com o Nome do Artista |");
    printf("\n ___________________________");
    printf("\n--> ");
    scanf(" %255[^\n]", MusicItem->info->artist);

    printf("\n ____________________________");
    printf("\n|Entre com a Letra da Música |");
    printf("\n ____________________________");
    printf("\n--> ");
    scanf(" %255[^\n]", MusicItem->info->letter);

    do{ //criação de um código único(ID) para a música
        printf("\n ________________________________________");
        printf("\n|Entre com um Código Único para a Música |");
        printf("\n ________________________________________");
        printf("\n--> ");
        setbuf(stdin, NULL);
        scanf("%d", &MusicItem->info->code);
        auxiliary = desc->first;
        while (auxiliary != NULL){
            if(auxiliary->info->code == MusicItem->info->code){
                verificacao = auxiliary->info->code;
                fprintf(stderr, "\n=== O CÓDIGO JÁ EXISTE NA LISTA! ===\n");
            }
            auxiliary = auxiliary->next;
        }
        
    }while(MusicItem->info->code == verificacao); //realiza o loop até possuir um ID válido

    MusicItem->info->views = 0; //inicializa as 'views' com 0
    MusicItem->next = NULL; //aponta para Null
    
    return MusicItem;
}
        