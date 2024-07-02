#include "../files-h/MusicsLib.h"


void PrintMusic(Desc *desc){
    if (desc == NULL || desc->first == NULL) {// Verificando se há elementos na lista
        fprintf(stderr, "\n=+= A Lista Está Vazia! =+=\n=+= Retornando ao Menu! =+=\n");
        return;
    }
    int code;
    char search;
        printf("\n _______________________________");
        printf("\n|Digite:                        |");
        printf("\n|[b]Buscar pelo Código          |");
        printf("\n|[v]Visualizar Todas as Músicas |");
        printf("\n _______________________________");
        printf("\n --> ");
        setbuf(stdin, NULL);
        scanf(" %c", &search);
        search=tolower(search);

        while (search != 'b' && search != 'v')//verifica se uma posição válida foi escolihida e, em caso negativo, repete o loop até uma válida aparecer
        {
            fprintf(stderr, "=== Opção Inválida! ===\n=== Tente Novamente! ===\n\n");
            sleep(2);
            system("clear");
            printf("\n _______________________________");
            printf("\n|Digite:                        |");
            printf("\n|[b]Buscar pelo Código          |");
            printf("\n|[v]Visualizar Todas as Músicas |");
            printf("\n _______________________________");
            printf("\n --> ");
            setbuf(stdin, NULL);
            scanf(" %c", &search);
            search=tolower(search);
        }

        switch(search){
            case 'b': //busca e exibe uma música a partir de seu código
                printf("\n _________________________________");
                printf("\n|Entre com o Código(ID) da Musica |");
                printf("\n _________________________________");
                printf("\n --> ");
                setbuf(stdin, NULL);
                scanf("%d", &code);
                    SearchMusic(desc, code);
                return;

            case 'v': //exibe todas as músicas da lista
                SearchAllMusics(desc);
                break;

            default: //caso padrão, função semelhante ao while da linha 22
                system("clear");
                fprintf(stderr, "=== Opção Inválida! ===\n=== Tente Novamente! ===\n\n");
                sleep(1.5);
        }
    
}