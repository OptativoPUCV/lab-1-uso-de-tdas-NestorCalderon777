#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();

   for(int k = 1 ; k < 11 ; k++){
      int *dato = malloc(sizeof(int));
      *dato = k;
      pushBack(L,dato);
   }
   
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {

   int sumaLista = 0;

   void* actual = first(L);

   while(actual != NULL){
      sumaLista += *(int*)actual;
      actual = next(L);
   }
   return sumaLista;

   return 0;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){

   void* actual = first(L);

   while(actual != NULL){
      if(*(int*)actual == elem){
         popCurrent(L);
         actual = next(L);
      }
      else actual = next(L);
   }

}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack* pila_aux = create_stack();

   while(top(P1) != NULL){
      push(pila_aux,top(P1));
      pop(P1);
   }

   while(top(pila_aux) != NULL){
      push(P2,top(pila_aux));
      push(P1, top(pila_aux));
      pop(pila_aux);
   }
   free(pila_aux);
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   char *PC = NULL;  
    int top = -1;     

    
    for (int k = 0; cadena[k] != '\0'; k++) {
        char current = cadena[k];

        
        if (current == '(' || current == '{' || current == '[') {
            top++;
            PC = (char *) realloc(PC, (top + 1) * sizeof(char));
            if (PC == NULL) {
                return 0;  
            }
            PC[top] = current;  
        } 
        
        else if (current == ')' || current == '}' || current == ']') {
            if (top == -1) {
                free(PC);  
                return 0;
            }

            
            char caracter = PC[top];
            if ((current == ')' && caracter == '(') || 
                (current == ']' && caracter == '[') || 
                (current == '}' && caracter == '{')) {
                top--;  
            } else {
                free(PC);  
                return 0;
            }
        }
}

