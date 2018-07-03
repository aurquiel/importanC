#include <stdio.h>
#include <stdlib.h>

typedef struct tNodo{
    int value;
    struct tNodo* siguiente;
}Nodo;

typedef struct tFila{
    int size;
    Nodo *front;
    Nodo *tail;
}Fila;

Nodo *getNodo(int fValue){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->value = fValue;
    nodo->siguiente = NULL;
    return nodo;
}

Fila *getFila()
{
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->size = 0;
    f->front = NULL;
    f->tail = NULL;
    return f;
}

void anadirFila(Fila *f, Nodo *nodo)
{
    if(f->front == NULL)
        f->front = nodo;
    else
        f->tail->siguiente = nodo;
    f->tail = nodo;
    f->size++;
}

int eliminarFila(Fila *f)
{
    if(f->size)
    {
        int returnValue = 0;
        Nodo * auxNodo = (Nodo*)malloc(sizeof(Nodo));
        auxNodo = f->front;
        returnValue = auxNodo->value;
        f->front = f->front->siguiente;
        free(auxNodo);
        f->size--;
        return returnValue;
    }
    return -1;
}

int main()
{
    Fila* myFila = getFila();
    Nodo *a1 = getNodo(5);
    Nodo *a2 = getNodo(15);
    Nodo *a3 = getNodo(25);
    Nodo *a4 = getNodo(35);
    anadirFila(myFila,a1);
    anadirFila(myFila,a2);
    anadirFila(myFila,a3);
    anadirFila(myFila,a4);
    printf("%d\n",eliminarFila(myFila));
    printf("%d\n",eliminarFila(myFila));
    printf("%d\n",eliminarFila(myFila));
    printf("%d\n",eliminarFila(myFila));
    printf("%d\n",eliminarFila(myFila));
    return 0;
}
