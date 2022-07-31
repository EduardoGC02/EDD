#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<stdbool.h>

struct nodo{
    struct nodo *padre;
    struct nodo *izq;
    struct nodo *der;
    int valor;
};

int data, data1, respuesta, opcion, opc;

struct nodo *crearNodo(struct nodo *padre, int valor);
void agregarValor(struct nodo *arbol, int valor);
void preOrden (struct nodo *padre);
void inOrden (struct nodo *padre);
void postOrden (struct nodo *padre); 

int main() {
	struct nodo *arbol;
	bool repetidor = true;
	while (repetidor){
		printf("-----------------------------------------------\n");
		printf("-----------------ARBOL BINARIO-----------------\n");

		printf("\n\tIngrese la opcion que desea realizar: \n");
		printf("\t\t1.- Agregar los valores del arbol \n");
		printf("\t\t2.- Recorrer el arbol \n");
		printf("\t\t3. Salir \n");
		printf("\n");
		scanf("%d", &opcion);
	
		switch(opcion){
			case 1:
				printf("\n\tIngrese el valor del primer nodo\n");
    			scanf("%d", &data);
    			arbol = crearNodo(NULL,data);
				do{
					printf("\n\tIngrese el valor del siguiente nodo\n");
					scanf("%d", &data1);
					agregarValor(arbol,data1);
		
					printf("\nDesea ingresar otro nodo?\n");
					printf("1.- Si 2.- No\n");
					scanf("%d", &respuesta);
					system("cls");
				}while(respuesta==1);
    

    			break;
    		
    		case 2:
				printf("\n\tIngrese la opcion que desea realizar: \n");
    			printf("\t\t1.- Recorrido pre-orden \n");
    			printf("\t\t2.- Recorrido in-orden \n");
    			printf("\t\t3.- Recorrido post-orden \n");
    			printf("\t\tIngrese otro valor para cancelar la operacion \n");
    			printf("\n");
    			scanf("%d", &opc);
    			switch(opc){
    				case 1:
    					printf("\nImprimiendo pre-orden \n");
    					preOrden(arbol);
    					printf("\n");
    					system("pause");
    					system("cls");
    					break;
    					
    				case 2:
    					printf("\nImprimiendo in-orden \n");
    					inOrden(arbol);
    					printf("\n");
    					system("pause");
    					system("cls");
    					break;
    					
    				case 3:
    					printf("\nImprimiendo post-orden \n");
    					postOrden(arbol);
    					printf("\n");
    					system("pause");
    					system("cls");
    					break;
    					
    				default:
    					break;
				}

    			system("cls");
				break;
				
			case 3:
				printf("\nSaliendo del programa...\n");
				repetidor = false;
				break;
			default:
				printf("Ingrese una opcion valida \n");
				system("pause");
				system("cls");
		}
	}
	return 0;
}

struct nodo *crearNodo(struct nodo *padre, int valor){
    struct nodo *n = calloc(sizeof(struct nodo),1);
    n->padre = padre;
    n->valor = valor;
    return n;
}

void agregarValor(struct nodo *arbol, int valor){
    struct nodo *temp, *pivote;
    int derecho = 0;
    if(arbol) {
        temp = arbol;
        while(temp){
            pivote = temp;
            if( valor > temp->valor){
                //derecho
                temp = temp->der;
                derecho = 1;
            }
            else {
                //izquierdo
                temp = temp->izq;
                derecho = 0;
            }
        }

        temp = crearNodo(pivote, valor);
        if(derecho) {
            printf("\tInsertando %i del lado derecho de %i \n", valor, pivote->valor);
            pivote->der = temp;

        }
        else {
            pivote->izq = temp;
            printf("\tInsertando %i del lado izquierdo de %i \n", valor, pivote->valor);
        }

    }
    else {
        printf("Error, el arbol no esta inicializado");
    }
}

void preOrden (struct nodo *padre) {
	if (padre != NULL) {
        printf("%d,", padre->valor);
        preOrden(padre->izq);
        preOrden(padre->der);
	}
}

void inOrden (struct nodo *padre) {
	if(padre != NULL){
	    inOrden(padre->izq);
	    printf("%d,", padre->valor);
        inOrden(padre->der);
	}
}

void postOrden (struct nodo *padre) {
	if(padre != NULL){
	    postOrden(padre->izq);
        postOrden(padre->der);
        printf("%d,", padre->valor);
	}
}
