#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_node linked_list_node;

struct linked_list_node {
    int numero;
    linked_list_node* prossimo;
};

void stampa_lista(linked_list_node* nodo) {
    if (nodo == NULL) return;
    
    printf("%d ", nodo -> numero);
    stampa_lista(nodo -> prossimo);
}

void libera_lista(linked_list_node* nodo) {
    if (nodo == NULL) return;

    linked_list_node* temporanea = nodo -> prossimo;
    free(nodo);

    libera_lista(temporanea);
}

void elimina_elemento(linked_list_node** primo, int da_cancellare) { 
    if (*primo == NULL) { 
        printf("L'elemento '%d' non e' stato trovato\n", da_cancellare); 
        exit(1);
    } 
 
    linked_list_node* prossimo = (*primo) -> prossimo;
    if ((*primo) -> numero == da_cancellare) { 
        linked_list_node* temporanea = *primo;
        *primo = prossimo;
        free(temporanea);
        return;
    } 
 
    elimina_elemento(&prossimo, da_cancellare);
}

int main() {
    linked_list_node* primo = NULL;
    linked_list_node* ultimo = NULL;
    int entrata = 0;

    printf("Per terminare inserire un numero non-positivo:\n");
    while (printf("Inserisci il numero: "), scanf("%d", &entrata), entrata > 0)
    {
        linked_list_node* nuovo_nodo = malloc(sizeof(linked_list_node));
        nuovo_nodo -> numero = entrata;
        nuovo_nodo -> prossimo = NULL;
        
        if (primo == NULL) {
            primo = nuovo_nodo;
            ultimo = nuovo_nodo;
        } else {
            ultimo -> prossimo = nuovo_nodo;
            ultimo = nuovo_nodo;
        }
    }

    int da_cancellare = 0;
    printf("Inserici numero da cancellare: ");
    scanf("%d", &da_cancellare);

    elimina_elemento(primo, da_cancellare);
    stampa_lista(primo);
    libera_lista(primo);

    return 0;
}