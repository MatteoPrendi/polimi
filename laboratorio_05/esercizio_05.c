#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_node {
    int numero;
    struct linked_list_node* prossimo;
} linked_list_node;

void push(linked_list_node** primo, int valore) {
    linked_list_node* nuovo = malloc(sizeof(linked_list_node));
    nuovo -> numero = valore;
    nuovo -> prossimo = *primo;
    *primo = nuovo;
}

int pop(linked_list_node** primo) {
    if (*primo == NULL) {
        printf("La pila e' vuota");
        exit(1);
    }

    linked_list_node* temp = *primo;
    int valore = temp -> numero;
    *primo = temp -> prossimo;
    free(temp);

    return valore;
}

void visualizza(linked_list_node** primo) {
    if (*primo == NULL) {
        printf("Errore: pila vuota!\n");
        exit(1);
    }

    printf("La lista (partendo dalla cima): ");
    while (*primo != NULL) {
        int elemento_rimosso = pop(primo);
        printf("%d ", elemento_rimosso);
    }
}

int main() {
    linked_list_node* pila = NULL;
    int entrata = 0;

    printf("Per terminare inserire un numero non-positivo:\n");
    while (printf("Inserisci il numero: "), scanf("%d", &entrata), entrata > 0) 
        push(&pila, entrata);

    visualizza(&pila);

    return 0;
}
