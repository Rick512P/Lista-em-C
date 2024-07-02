/*
  Autor: Érick Santos Matos
  Matrícula: 2310100966
  Atividade Semi-presencial 4 - Pilha Músicas
*/

#include "../File-h/biblioteca.h"

Desc * criaDesc(){
    Desc *Descritor = (Desc *)malloc(sizeof(Desc));
    Descritor->pilha=NULL;
    Descritor->tamanho=0;
    return Descritor;
}

Nodo * criaNodo(){
    Nodo *elemento = (Nodo *)malloc(sizeof(Nodo));
    elemento->prox=NULL;
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

void inserePilha(Desc *descritor, Nodo *elemento, Musica *musica){
    elemento->info = musica;
    if (descritor->tamanho == 0) // Verifica se a Pilha esta Vazia
    {   
        descritor->pilha = elemento;
        descritor->tamanho++;
    }
    else{
        Nodo *aux=descritor->pilha, *auxanterior;
        while (aux != NULL)
        {
            auxanterior = aux;
            aux = aux->prox;
        }
        auxanterior->prox = elemento;
        descritor->tamanho++;
    }
}

Nodo * POP(Desc *descritor)//remove elemento do topo da lista
{
    if (descritor->tamanho == 0)
    {
        puts("Pilha vazia!");
    }
    else if(descritor->tamanho == 1){
        descritor->pilha = NULL;
        descritor->tamanho = 0;
    }
    else{
        Nodo *aux = descritor->pilha, *auxanterior;
        int size = descritor->tamanho;
        size--;
        while (aux->prox != NULL)
        {
            auxanterior = aux;
            aux = aux->prox;
        }
        auxanterior->prox = NULL;
        descritor->tamanho--;
        return aux;
    }

}

void TOP(Desc *pilha){
    if (pilha->tamanho == 0)
    {
        puts("Pilha vazia!");
    }
    else{
    
        Nodo *aux=pilha->pilha, *auxanterior;
        while (aux != NULL)
        {
            auxanterior = aux;
            aux = aux->prox;
        }
        auxanterior->info->execucoes++;
        printf("Artista/Banda: %s\n",auxanterior->info->artista);
        printf("Título: %s\n",auxanterior->info->titulo);
        printf("Letra: %s\n",auxanterior->info->letra);
        printf("Execuções: %d\n",auxanterior->info->execucoes);
        printf("ID: %d\n",auxanterior->info->codigo);
    }
}

void ImprimirPIlha(Desc *descritor){
    if (descritor->tamanho == 0)
    {
        puts("Pilha vazia!");
    }
    else{
        Nodo *aux = descritor->pilha;
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

void limpaPilha(Desc *descritor){
    Nodo *aux = descritor->pilha, *auxanterior;
    while (aux != NULL)
    {   
        if (descritor->tamanho == 1)
            free(descritor);
        else{
            auxanterior = aux;
            aux = aux->prox;
            free(auxanterior);
        }
    }
    descritor->tamanho = 0;
    descritor->pilha = NULL;
}
