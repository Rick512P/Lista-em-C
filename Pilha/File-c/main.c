/*
  Autor: Érick Santos Matos
  Matrícula: 2310100966
  Atividade Semi-presencial 4 - Pilha Músicas
*/

#include "../File-h/biblioteca.h"

int main(){
    int op=1;
    Desc *Pilha = NULL;
    Nodo *elemento = NULL;
    Musica *musica = NULL;
    do{
        printf("1- Criar Pilha\n"); //Cria Pilha
        printf("2- Push\n"); //Insere elemento no topo da lista
        printf("3- POP\n"); //Remove elemento no topo da lista
        printf("4- TOP\n"); //Exibe o elemento do topo da lista
        printf("5- EMPTY\n"); //Retorna 1 para pilha vazia e 0 para pilha não vazia
        printf("6- Imprimir PIlha\n"); //Exibe todos os elementos da pilha
        printf("0- Sair\n"); //Libera espaço de memória e encerra o programa
        printf("--> ");
        scanf("%d", &op);
        puts("");

        switch (op){
            case 0:
                if (Pilha != NULL)
                    limpaPilha(Pilha);
                break;
            case 1:
                Pilha = criaDesc();
                if (Pilha !=NULL)
                    puts("Lista Criada com Sucesso");
                break;
            case 2:
                if (Pilha == NULL){
                    puts("Crie uma Pilha primeiro!");
                }
                else{
                    elemento = criaNodo();
                    musica = preencheElemento();
                    inserePilha(Pilha, elemento, musica);
                }
                break;
            case 3:
                if (Pilha == NULL){
                    puts("Crie uma Pilha primeiro!");
                }
                else{
                    elemento = POP(Pilha);                
                }
                break;

            case 4:
                if (Pilha == NULL){
                    puts("Crie uma Pilha primeiro!");
                }
                else{
                    TOP(Pilha);
                }
                break;
            case 5:
                if (Pilha == NULL){
                    puts("Crie uma Pilha primeiro!");
                }
                else{
                    if (Pilha->tamanho == 0)
                    {
                        puts("1");
                    }
                    else{
                        puts("0");
                    }
                    
                }
                break;
            case 6:
                if (Pilha == NULL){
                    puts("Crie uma Pilha primeiro!");
                }
                else{
                    ImprimirPIlha(Pilha);
                }
                break;

            default:
                puts("Opção Inválida!");
                break;
        }
        puts("");
    }while (op != 0);

    return 0;
    
}
