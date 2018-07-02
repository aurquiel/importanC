#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int data;
  struct node *next;
}Node;

typedef struct list {
  Node *head;
} List;

List * emptylist(void);
void add(int data, List *list);
void delete(int data, List *list);
void display(List *list);
void reverse(List *list);
void destroy(List *list);
Node * createnode(int data);

//Implemetantion

Node * createnode(int data){
  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

List * emptylist(){
  List * list = malloc(sizeof(List));
  list->head = NULL;
  return list;
}

void display(List *list) {
  Node *current = list->head;
  if(list->head == NULL)
    printf("Void list\n");
  while(current->next != NULL){
    printf("%d,", current->data);
    current = current->next;
  }
  printf("%d\n", current->data);
}

void add(int data, List *list){
  Node *current = NULL;
  if(list->head == NULL){
    list->head = createnode(data);
  }
  else {
    current = list->head;
    while (current->next!=NULL){
      current = current->next;
    }
    current->next = createnode(data);
  }
}

void delete(int data, List *list){
  Node *current = list->head;
  Node *previous = current;
  while(current != NULL){
    if(current->data == data)
    {
      previous->next = current->next;
      if(current == list->head)
        list->head = current->next;
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
}

void reverse(List *list){
  Node *reversed = NULL;
  Node *current = list->head;
  Node *temp = NULL;
  while(current != NULL){
    temp = current;
    current = current->next;
    temp->next = reversed;
    reversed = temp;
  }
  list->head = reversed;
}

void destroy(List * list){
  Node * current = list->head;
  Node * next = current;
  while(current != NULL){
    next = current->next;
    free(current);
    current = next;
  }
  free(list);
}


int main()
{
    List *list = emptylist();
    add(1, list);
    add(20, list);
    add(2, list);
    add(5, list);
    add(8, list);
    add(9, list);
    add(13, list);
    display(list);
    //Elaborated applicattions
    delete(2, list);
    display(list);
    delete(1, list);
    display(list);
    delete(20, list);
    display(list);
    reverse(list);
    printf("Reversed: ");
    display(list);
    destroy(list);
    return 0;
}
