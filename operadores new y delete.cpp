#include<iostream>
#include<stdio.h>

int main()
{
   int n;
   
   printf("Numero de enteros para reservar: ");
   scanf("%d", &n);
   
   int *x = new int[n]; //Asignacion de memoria dinamica
   
   for(int i=0; i<n; i++){
   	*(x+i) = i;
   }
   for(int i=0;i<n;i++){
   	printf("%d ", x[i]);
   }
   
   delete [](x); //Eliminando la memoria dinamica
   return 0;
}
