#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Nodo {
	char producto[50];
	struct Nodo* siguiente;
} Nodo;
typedef struct Lista {
	Nodo* cabeza;
	int longitud;
} Lista;

struct Lista* crearLista(){
	struct Lista* lista = (struct Lista*) malloc(sizeof(struct Lista));
	lista->cabeza = NULL;
	lista->longitud = 0;
	return lista;
}

Nodo* CrearNodo(char *producto){
	Nodo* nodo = (Nodo*) malloc (sizeof (Nodo));
	strncpy(nodo->producto, producto, 50);
	nodo->siguiente=NULL;
	return nodo;
}

void DestruirNodo(Nodo* nodo) {
	free(nodo);
}

void InsertarInicio(Lista* lista, char *producto){
	Nodo* nodo = CrearNodo(producto);
	nodo->siguiente = lista->cabeza;
	lista->cabeza = nodo;
	lista->longitud++;
}
	
void InsertarFinal(Lista* lista, char *producto){
	Nodo*nodo = CrearNodo(producto);
	if (lista->cabeza == NULL) {//si la lista esta vacia
		lista->cabeza = nodo;
	} else {
		Nodo* puntero = lista->cabeza;
		while (puntero->siguiente){
			puntero = puntero->siguiente;	
		}
		puntero->siguiente = nodo;
	}
	lista->longitud++;
}

void InsertarN(int n, Lista* lista, char *producto){

	Nodo* nodo = CrearNodo(producto);
	if (lista->cabeza == NULL) {
		lista->cabeza == nodo;
	} else {
		Nodo* puntero = lista->cabeza;
		int posicion = 0;
		while (posicion < n && puntero->siguiente){
			puntero = puntero->siguiente;
			posicion++;
		} 
		nodo->siguiente = puntero->siguiente; //se conecta el nuevo nodo con el nodo posterior
		puntero->siguiente = nodo; /// se conecta el nuevo nodo con el nodo anterior
	}
	lista->longitud++;
}
void Buscar(int n, Lista* lista){
	if (lista->cabeza == NULL){
		printf ("La lista se encuentra vacia \n");
	} else {
		Nodo* puntero = lista->cabeza;
		int posicion = 0;
		while (posicion < n && puntero->siguiente){
			puntero = puntero->siguiente;
			posicion++;
		}
		if (posicion != n){
			printf ("\n No hay un producto en esta posicion \n");
		}else {
			printf("\n%s\n",&puntero->producto);
		}
	}
}

int longitud(Lista* lista) {
	return lista->longitud;
}

void MostrarLista(Lista* lista){
	if (lista->cabeza == NULL){
		printf("\n La lista se encuentra vacia \n");
	} else {
		Nodo* puntero = lista->cabeza;
		int posicion = 0;
		while (posicion < lista->longitud){
			printf(" %s \n", &puntero->producto);
			puntero = puntero->siguiente;
			posicion++;
		}
	}
}

void EliminarPrimero(Lista* lista){
	if(lista->cabeza){
	Nodo* eliminado = lista->cabeza;
	lista->cabeza = lista->cabeza->siguiente;
	DestruirNodo(eliminado);
	lista->longitud--;
	printf ("El primer producto ha sido eliminado de la lista\n");
	}  else {
		printf("\n La lista ya se encuentra vacia \n");
	}
}

void EliminarUltimo(Lista* lista){
	if(lista->cabeza){
		if(lista->cabeza->siguiente) {
		
		Nodo* puntero = lista->cabeza;
		while (puntero->siguiente->siguiente){
			puntero = puntero->siguiente;
		}
		Nodo* eliminado = puntero->siguiente;
		puntero->siguiente=NULL;
		DestruirNodo(eliminado);
		lista->longitud--;
		printf ("El ultimo producto ha sido eliminado de la lista\n");
		} else {//si solo hay un elemento en la lista
			Nodo* eliminado = lista->cabeza;
			lista->cabeza = NULL;
			DestruirNodo(eliminado);
			lista->longitud--;
			printf ("El ultimo producto ha sido eliminado de la lista\n");
			printf ("\n Ahora la lista esta vacia \n");
		}
	} else{
		printf ("\n La lista ya se encuentra vacia \n");
	}
}

void EliminarN(int n, Lista* lista){
	if (lista->cabeza) {
		if (n == 0) {
			Nodo* eliminado = lista->cabeza;
			lista->cabeza = lista->cabeza->siguiente;
			DestruirNodo(eliminado);
			lista->longitud--;
			printf ("El producto ha sido eliminado de la lista\n");
		} else if (n < lista->longitud) {
			Nodo* puntero = lista->cabeza;
			int posicion = 0;
			while(posicion < (n - 1)) {// nos ubicamos en el nodo anterior al que queremos eliminar
			puntero = puntero->siguiente;
			posicion++;
		}
		//eliminamos el nodo siguiente
		Nodo* eliminado = puntero->siguiente;
		puntero->siguiente = eliminado->siguiente;//conectamos el nodo anterior al que le sigue al eliminado
		DestruirNodo(eliminado);
		lista->longitud--;	
		printf ("El producto ha sido eliminado de la lista\n");
		}else{
			printf("\n No hay ningun producto en esta posicion \n");
		}
	}
}




int main(){
	struct Lista* lista = crearLista();
	int repetidor = true;
	int opcion;
	while (repetidor){
	
	printf ("\n\tIngrese la opcion que desea realizar: \n");
	printf ("\t\t1.- Agregar un producto \n");
	printf ("\t\t2.- Buscar una posicion en la lista \n");
	printf ("\t\t3.- Mostrar toda la lista \n");
	printf ("\t\t4.- Mostrar la cantidad de productos en la lista \n");
	printf ("\t\t5.- Eliminar un producto \n");
	printf ("\t\t6.- Salir \n");
	printf ("\n");
	scanf ("%d", &opcion);
	switch (opcion){
		case 1: 
		char producto[50];
		int opcAg;
		printf ("\n\tIngrese la opcion que desea realizar: \n");
		printf ("\t\t1.- Agregar un producto al comienzo \n");
		printf ("\t\t2.- Agregar un producto al final \n");
		printf ("\t\t3.- Insertar un producto en una posicion especifica \n");
		printf ("\t\tIngrese otro valor para cancelar la operacion \n");
		printf ("\n");
		scanf ("%d", &opcAg);
		switch(opcAg){
			case 1: 
			printf ("\tIngrese el nombre del producto \n");
			scanf ("%s", &producto);
			printf("Agregando producto...\n");
			InsertarInicio(lista,producto);
			break;
			
			case 2: 
			printf ("\tIngrese el nombre del producto \n");
			scanf ("%s", &producto);
			printf("Agregando producto...\n");
			InsertarFinal(lista,producto);
			break;
			
			case 3:
			int n;
			printf ("\tIngrese el nombre del producto \n");
			scanf ("%s", &producto);
			printf("Digite la posicion en la que desea introducir el producto \n");
			scanf ("%d", &n);
			printf("Agregando producto...\n");
			InsertarN(n,lista,producto);
			break;
			
			default:
			break;
		}
		system("pause");
system ("cls");
		break;
		
		case 2:
		int n; 
		printf("\n\tDigite la posicion del producto que desea buscar \n");
		scanf ("%d", &n);
		Buscar(n,lista);
		system("pause");
system ("cls");
		break;
		
		case 3:
		printf ("\n--------LISTA--------\n");
		MostrarLista(lista);
		system("pause");
system ("cls");
		break;
		
		case 4:	
		printf ("\n\tLa lista tiene %d productos \n", longitud(lista));
		system("pause");
system ("cls");
		break;
		
		case 5:
		int opcElim;
		printf ("\n\tIngrese la opcion que desea realizar: \n");
		printf ("\t\t1.- Eliminar el primer producto \n");
		printf ("\t\t2.- Eliminar el ultimo producto \n");
		printf ("\t\t3.- Eliminar una posicion de producto especifica \n");
		printf ("\t\tIngrese otro valor para cancelar la operacion \n");
		scanf ("%d", &opcElim);
		switch(opcElim) {
			case 1: 
			EliminarPrimero(lista);
			break;
			
			case 2: 
			EliminarUltimo(lista);
			break;
			
			case 3: 
			int n; 
			printf("Ingrese la posicion del producto que desea eliminar: \n");
			scanf ("%d", &n);
			EliminarN (n,lista);
			break;
		
			default:
			break;
		}
		system("pause");
system ("cls");
		break;
		case 6:
			printf("Saliendo del programa...\n");
			repetidor = false;
	break;
	default:
		printf("Ingrese una opcion validad \n");
		system("pause");
system ("cls");
	}

}
	return 0;
}
