#include <stdio.h>
#include <stdlib.h>

typedef struct tNodo{
    int valor;
    struct tNodo *next;
}Nodo;

typedef struct Tstack{
    int size;
    Nodo* top;
}Stack;

Stack *getNewStack(){
    Stack *s= (Stack*)malloc(sizeof(Stack));
    s->size = 0;
    s->top = NULL;
    return s;
}
void push(Stack *s, int value)
{
    if(s)
    {
        Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
        nodo->valor = value;
        nodo->next = s->top;
        s->top = nodo;
        s->size++;
    }
    else
    {
        perror("Strack NULL\n");
    }
}

void readStack(Stack *s)
{
    if(s && s->size)
    {
        printf("%d\n",s->top->valor);
    }
}

Nodo *pop(Stack *s)
{
    if(s)
    {
        if(s->size)
        {
            Nodo *aux = (Nodo*)malloc(sizeof(Nodo));
            aux = s->top;
            s->top = s->top->next;
            s->size--;
            return(aux);
        }
    }
    perror("Void Stack\n");
    return NULL;
}

int main()
{
    Stack *s = getNewStack();
    push(s,45);
    push(s,65);
    push(s,95);
    Nodo * cuales = (Nodo*)malloc(sizeof(Nodo));
    cuales = pop(s);
    printf("%d\n", cuales->valor);
    readStack(s);
    free(s);
    return 0;
}
