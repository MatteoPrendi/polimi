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

void inserici_valore(linked_list_node* primo, int valore, int indice) {
    int i = 0;
    linked_list_node* nodo_attuale = primo;

    while (nodo_attuale != NULL) {
        if (i == indice) {
            linked_list_node* nuovo_nodo = malloc(sizeof(linked_list_node));
            nuovo_nodo -> numero = valore;
            nuovo_nodo -> prossimo = nodo_attuale -> prossimo;
            nodo_attuale -> prossimo = nuovo_nodo;
            return;
        }
        
        nodo_attuale = nodo_attuale -> prossimo;
        i++;
    }

    printf("Indice fuori range");
    libera_lista(primo);
    exit(1);
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

    int indice = 0, valore = 0;
    printf("Inserici l'indice: ");
    scanf("%d", &indice);

    printf("Inserici il valore: ");
    scanf("%d", &valore);

    inserici_valore(primo, valore, indice);

    stampa_lista(primo);
    libera_lista(primo);

    return 0;
}