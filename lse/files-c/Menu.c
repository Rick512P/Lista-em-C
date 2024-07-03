#include "../files-h/MusicsLib.h"

int main(void){
    char op;
    int position, code, verifica = 1;
    Desc *desc = NULL;
    Node *MusicItem;
    do{//início do loop e menu de opções
        printf("\n| +    [a]Adiciona uma Nova Música a Lista     + |");
        printf("\n| +    [b]Buscar uma musica - Código           + |");
        printf("\n| +    [c]Criar Lista                          + |");
        printf("\n| +    [e]Exibir Músicas - Código ou Todas     + |");
        printf("\n| +    [r]Remover Uma Música                   + |");
        printf("\n| +    [s]Sair                                 + |");
        printf("\nOpção: ");
        setbuf(stdin,NULL);
        scanf(" %c", &op);
        printf("\n");
        op=tolower(op);
        setbuf(stdin,NULL);

        switch(op){
            case 's':            
                if (desc != NULL) {
                    //libera o espaço de memória referente a lista
                    FreeMem(desc);
                }

                printf("Saindo...");
                fflush(stdout); // faz com que a mensagem sempre apareça previouses da execução do sleep 
                sleep(2); //sleep para não apagar mensagem imediatamente
                system("clear");

                break;

            case 'a':// inserção de elementos na lista
                if (verifica == 1)//verificação da existencia da lista
                {
                    printf("=+= A Lista não Foi Criada! =+=\n=+= Crie uma Antes de Continuar! =+=\n");
                    break;
                }
                MusicItem = Musics(desc);
                printf("\n __________________________________________");
                printf("\n|Digite a Posição de Inserção na Sua Lista |");
                printf("\n __________________________________________");
                printf("\n--> ");
                setbuf(stdin, NULL);
                scanf("%d", &position);
                printf("\n");
                setbuf(stdin, NULL);
                InsertMusic(desc, MusicItem, position);
                break;
            
            case 'b'://busca de música via código
                if (verifica == 1)//verificação da existencia da lista
                {
                    printf("=+= A Lista não Foi Criada! =+=\n=+= Crie uma Antes de Continuar! =+=\n");
                    break;
                }
                else if (desc->first == NULL) {
                    //verificação de lista vazia;
                    printf("Lista Vazia!");
                    break;
                }
                
                printf("\n _________________________________________________");
                printf("\n|Digite o Código da Música que Desejas Visualizar |");
                printf("\n _________________________________________________");
                printf("\n--> ");
                scanf("%d", &code);
                SearchMusic(desc, code);
                break;

            case 'c': //criação de uma lista
                if (desc == NULL){//verifica existencia da lista
                    desc = InitDesc();
                    printf("\n ________________________________");
                    printf("\n|A Lista Foi Criada com Sucesso! |");
                    printf("\n|Adicione Novas Musicas!         |");
                    printf("\n ________________________________\n");
                    verifica=0;
                }
                else
                    puts("Lista já criada!");
                break;

            case 'e'://busca de música por código ou impressão de todas as músicas incrementando as 'views'
                if (verifica == 1)//verificação da existencia da lista
                {
                    printf("=+= A Lista não Foi Criada! =+=\n=+= Crie uma Antes de Continuar! =+=\n");
                    break;
                }
                else if (desc->first == NULL) {
                    //verificação de lista vazia;
                    printf("Lista Vazia!");
                    break;
                }
                PrintMusic(desc);
                break;

            case 'r'://remoção de elementos da lista
                if (verifica == 1)//verificação da existencia da lista
                {
                    printf("=+= A Lista não Foi Criada! =+=\n=+= Crie uma Antes de Continuar! =+=\n");                
                    break;
                }
                else if (desc->first == NULL) {
                    //verificação de lista vazia;
                    printf("Lista Vazia!");
                    break;
                }
                printf("\n| --> Tamanho da lista: %d\n", desc->size);
                printf("\n _______________________________________________________");
                printf("\n|Digite a Posição da Música a Ser Removida da Sua Lista |");
                printf("\n _______________________________________________________");
                printf("\n--> ");
                scanf("%d", &position);
                RemoveMusic(desc, position);
                break;

            default://caso padrão
                printf("\n+++ Opcao invalida +++\n");
                break;
        }
    }while(op != 's');//verifica a necessidade de continuar o loop
    return 0;
}