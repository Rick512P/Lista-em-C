#include "../files-h/MusicsLib.h"

void InsertMusic(Desc *desc, Node *MusicItem, int position){ //inserção da música na lista de acordo com a posição
    if((desc->first == NULL)){ //insere no inicio caso lista vazia
        MusicItem->next = desc->first;
        MusicItem->previous = NULL;
        desc->first = MusicItem;
        desc->final = MusicItem;
        printf("=+= Música inserida no inicio da lista =+=\n");
        desc->size++;
    }

    else if((position == 0)){ //insere no inicio caso posição 0
        MusicItem->next = desc->first;
        MusicItem->previous = NULL;
        desc->first = MusicItem;
        printf("=+= Música inserida no inicio da lista =+=\n");
        desc->size++;
    }

    else { 
        Node *auxiliary = desc->first;
        if(position >= desc->size){ //adiciona no fim caso posição maior que o tamanho da lista
            while(auxiliary->next != NULL){
                auxiliary = auxiliary->next;
            }
            MusicItem->next = NULL;
            auxiliary->next = MusicItem;
            MusicItem->previous = desc->final;
            desc->final = MusicItem;
            desc->size++;
            printf("=+= Música Adicionada No Final Da Lista =+=\n");
            return;
        }
        
        else {// adiciona na posição escolhida caso passe pelas outras opções
            int i=0;
            Node *auxprev;
            if (position <= desc->size/2){ // verifica se é mais vantajoso começar pelo início da lista
				while(auxiliary != NULL){
                    auxprev = auxiliary;
					auxiliary = auxiliary->next;
					i++;
                    if (i == position){
                        auxprev->next = MusicItem;
                        MusicItem->previous = auxprev;
                        MusicItem->next = auxiliary;
                        auxiliary->previous = MusicItem;
                        desc->size++;
                        printf ("=+= Música Inserida na Posição %d da Lista =+=\n",position);
                        return;
                    }
				}
            }
            else if (position > desc->size/2){ // verifica se é mais vantajoso começar pelo fim da lista
                Node *auxiliary = desc->final;
                while(auxiliary != NULL){
                    auxprev = auxiliary;
					auxiliary = auxiliary->previous;
					i--;
                    if (i == position){
                        auxprev->previous = MusicItem;
                        MusicItem->next = auxprev;
                        MusicItem->previous = auxiliary;
                        auxiliary->next = MusicItem;
                        desc->size++;
                        printf ("=+= Música Inserida na Posição %d da Lista =+=\n",position);
                        return;
                    }
				}
            }
        }      
    }
}