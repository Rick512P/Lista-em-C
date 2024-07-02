#include "../files-h/MusicsLib.h"

void InsertMusic(Desc *desc, Node *MusicItem, int position){ //inserção da música na lista de acordo com a posição
    if((desc->first == NULL) || (position == 0)){ //insere no inicio caso posição 0 ou lista vazia
        MusicItem->next = desc->first;
        desc->first = MusicItem;
        printf("=+= Música inserida no inicio da lista =+=\n");
        desc->size++;
    }

    else { 
        Node *auxiliary = desc->first;
        if(position > desc->size){ //adiciona no fim cado posição maior que o tamanho da lista
            while(auxiliary->next != NULL){
                auxiliary = auxiliary->next;
            }
            auxiliary->next = MusicItem;
            desc->size++;
            printf("=+= Música Adicionada No Final Da Lista =+=\n");
            return;
        }
        
        else {// adiciona na posição escolhida caso passe pelas outras opções
            int i=0;
            Node *previous;
				while(auxiliary != NULL){
                    previous = auxiliary;
					auxiliary = auxiliary->next;
					i++;
                    if (i == position){
                        previous->next = MusicItem;
                        MusicItem->next = auxiliary;
                        desc->size++;
                        printf ("=+= Música Inserida na Posição %d da Lista =+=\n",position);
                        return;
                    }
				}
        }      
    }
}