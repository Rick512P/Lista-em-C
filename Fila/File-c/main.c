/*
  Autor: Érick Santos Matos
  Matrícula: 2310100966
  Atividade Semi-presencial 5 - Fila Músicas
*/

#include "../File-h/biblioteca.h"

int main(){
    int op=1;
    DescFila *Queue = NULL;
    NodoFila *elemento = NULL;
    MusicaFIla *MusicaFIla = NULL;
    do{
        printf("1- Criar Queue\n"); //Cria A FIla
        printf("2- ENQUEUE\n"); //Insere elemento no fim da fila
        printf("3- DEQUEUE\n"); //Remove o primeiro elemento da fila e retorna
        printf("4- LENGHT\n"); //Exibe o numero de itens da fila
        printf("5- EMPTY\n"); // Retorna true(1) se a Fila estiver vazia; caso contrário, retorna false(0).
        printf("6- Imprimir Fila\n"); //Exibe todos os elementos da queue
        printf("7- DELETE\n"); //Faz a fila FIcar Vazia
        printf("0- Sair\n"); //Libera espaço de memória e encerra o programa
        printf("--> ");
        scanf("%d", &op);
        puts("");

        switch (op){
            case 0:
                if (Queue !=NULL)
                    if (Queue->head == NULL)
                        free(Queue);
                    else
                        limpaQueue(Queue);
                break;
            case 1:
                Queue = criaDescFila();
                if (Queue !=NULL)
                    puts("Lista Criada com Sucesso");
                break;
            case 2:
                if (Queue == NULL){
                    puts("Crie uma Queue primeiro!");
                }
                else{
                    elemento = criaNodoFila();
                    MusicaFIla = preencheElemento();
                    ENQUEUE(Queue, elemento, MusicaFIla);
                }
                break;
            case 3:
                if (Queue == NULL){
                    puts("Crie uma Queue primeiro!");
                }
                else{
                    elemento = DEQUEUE(Queue);                
                }
                break;

            case 4:
                if (Queue == NULL){
                    puts("Crie uma Queue primeiro!");
                }
                else{
                    printf("Quantia de elementos na Fila: %d", Queue->tamanho);
                }
                break;
            case 5:
                if (Queue == NULL){
                    puts("Crie uma Queue primeiro!");
                }
                else{
                    if (Queue->tamanho == 0)
                    {
                        puts("1");
                    }
                    else{
                        puts("0");
                    }
                    
                }
                break;
            case 6:
                if (Queue == NULL){
                    puts("Crie uma Queue primeiro!");
                }
                else{
                    ShowQueue(Queue);
                }
                break;
            case 7:
                Queue->head = NULL;
                Queue->tail = NULL;
                Queue->tamanho = 0;
                break;
            default:
                puts("Opção Inválida!");
                break;
        }
        puts("");
    }while (op != 0);

    return 0;
    
}
