#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

struct nodo {
    int data;
    struct nodo* sig;
};

struct cola {
    struct nodo *primero, *ultimo; // se guarda el primer y ultimo nodo de la cola
};

struct nodo* crearNodo(int data) { // metodo para crear nodo
    struct nodo* nuevo = (struct nodo*)malloc(sizeof (struct nodo));

    nuevo->data = data; //informacion que contiene el nodo
    nuevo->sig = NULL;

    return nuevo;
}

struct cola* crearCola() { // metodo para crear la cola
    struct cola* c = (struct cola*)malloc(sizeof(struct cola));
    c->primero = c->ultimo = NULL;// por ahora no hay nodos en la cola

    return c;
}

void enQueue(int data, struct cola** c) { // ingresar nodo, se ingresa los datos del nodo y se pasa la cola como puntero
    struct nodo* nuevo = crearNodo(data);

    //si la cola esta vacia
    if((*c)->primero == NULL){ 
        (*c)->primero = (*c)->ultimo = nuevo;
        return;
    }

    // si la cola no esta vacia
    else{
         (*c)->ultimo->sig = nuevo;
        (*c)->ultimo = nuevo;   
    }

}

int deQueue(struct cola** c) { //eliminar nodo de la cola

    // si la cola esta vacia
    if((*c)->primero == NULL) return INT_MIN;

    // si la cola no esta vacia
    struct nodo* eliminado = (*c)->primero;
    int data = eliminado->data;

    // eliminamos el nodo de la cola
    (*c)->primero = eliminado->sig;

    if((*c)->primero == NULL) {
        (*c)->ultimo = NULL;
    }

    free(eliminado);
    return data;
}

void mostrar(struct cola** c){ //recorrer la cola

    //si la cola esta vacia
    if((*c)->primero == NULL) return;

    // si no esta vacia
    printf("Primero: %d\nUltimo: %d\n", (*c)->primero->data, (*c)->ultimo->data);

    struct nodo* actual = (*c)->primero;
    while(actual) {
        printf("%d, ", actual->data);
        actual = actual->sig;
    }
    printf("\n-----------\n");
}

int main(int argc, char *argv[]){
    struct cola* c = crearCola();

    enQueue(6, &c);
    enQueue(-42, &c);
    enQueue(-9, &c);
    enQueue(72, &c);

    mostrar(&c);

    for(int i=0;i<5;i++) {
        printf("Eliminado: %d\n", deQueue(&c));
        mostrar(&c);
    }

    return 0;
}