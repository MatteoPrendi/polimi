#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_node linked_list_node;

struct linked_list_node {
    int numero;
    linked_list_node* prossimo;
};

void stampa_lista(linked_list_node* primo) {
    linked_list_node* nodo_attuale = primo;

    while (nodo_attuale != NULL) {
        printf("%d ", nodo_attuale -> numero);
        nodo_attuale = nodo_attuale -> prossimo;
    }
}

void libera_lista(linked_list_node* primo) {
    linked_list_node* nodo_attuale = primo;

    while (nodo_attuale != NULL) {
        linked_list_node* prossimo = nodo_attuale -> prossimo;
        free(nodo_attuale);

        nodo_attuale = prossimo;
    }
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

    stampa_lista(primo);
    libera_lista(primo);

    return 0;
}