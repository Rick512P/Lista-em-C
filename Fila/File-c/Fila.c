/*
  Autor: Érick Santos Matos
  Matrícula: 2310100966
  Atividade Semi-presencial 5 - Fila Músicas
*/

#include "../File-h/biblioteca.h"

Desc * criaDesc(){
    Desc *Descritor = (Desc *)malloc(sizeof(Desc));
    Descritor->head=NULL;
    Descritor->tail=NULL;
    Descritor->tamanho=0;
    return Descritor;
}

Nodo * criaNodo(){
    Nodo *elemento = (Nodo *)malloc(sizeof(Nodo));
    elemento->prox=NULL;
    elemento->ante=NULL;
    return elemento;
}

Musica * preencheElemento(){
    Musica *elemento = (Musica *)malloc(sizeof(Musica));
    char auxiliar[256];
    puts("Entre com o nome do artista/banda: ");
    scanf(" %255[^\n]", auxiliar);
    strcpy(elemento->artista, auxiliar);
    puts("Entre com o Título da Música: ");
    scanf(" %255[^\n]", auxiliar);
    strcpy(elemento->titulo, auxiliar);
    puts("Entre com a Letra da Música: ");
    scanf(" %255[^\n]", auxiliar);
    strcpy(elemento->letra, auxiliar);
    puts("Entre com o código Único da Música: ");
    scanf("%d", &elemento->codigo);
    elemento->execucoes = 0;
    return elemento;
}

void ENQUEUE(Desc *descritor, Nodo *elemento, Musica *musica){
    elemento->info = musica;
    if (descritor->tamanho == 0) // Verifica se a Fila esta Vazia
    {   
        descritor->head = elemento;
        descritor->tail = elemento;
        descritor->tamanho++;
    }
    else{
        Nodo *aux=descritor->tail;
        aux->prox = elemento;
        elemento->ante = aux;
        descritor->tail = elemento;
        descritor->tamanho++;
    }
}

Nodo * DEQUEUE(Desc *descritor)//remove o primeiro elemento da Fila
{
    if (descritor->tamanho == 0)
    {
        puts("Queue vazia!");
    }
    else if(descritor->tamanho == 1){
        descritor->head = NULL;
        descritor->tail = NULL;
        descritor->tamanho = 0;
    }
    else{
        Nodo *aux = descritor->head;
        descritor->head->prox->ante = NULL;
        descritor->head = descritor->head->prox;
        descritor->tamanho--;
        return aux;
    }

}

void ShowQueue(Desc *descritor){
    if (descritor->tamanho == 0)
    {
        puts("Queue vazia!");
    }
    else{
        Nodo *aux = descritor->head;
        while (aux != NULL)
        {
            printf("Artista/Banda: %s\n",aux->info->artista);
            printf("Título: %s\n",aux->info->titulo);
            printf("Letra: %s\n",aux->info->letra);
            printf("Execuções: %d\n",aux->info->execucoes);
            printf("ID: %d\n",aux->info->codigo);
            puts("");
            aux->info->execucoes++;
            aux = aux->prox;
        }
    }
}

void limpaQueue(Desc *descritor){
   
    Nodo *aux=descritor->head;
    while (aux != NULL)
    {
        if (descritor->tamanho == 1)
            free(descritor);
        else
            free(aux->ante);
        aux = aux->prox;
    }
}
