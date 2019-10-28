#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct node {char * name; struct node * next;};

void print_list(struct node * firstnode){
  printf("[ ");
  
  struct node * currentnode = firstnode;
  while (currentnode != NULL){
    printf("%s ", currentnode->name);
    currentnode = currentnode->next;
  }
  
  printf("]\n");
}

struct node * insert_front(struct node * firstnode, char * thisname){
  struct node * new = malloc(sizeof(struct node));
  new->next = firstnode;
  new->name = thisname;

  return new;
}

struct node * free_list(struct node * firstnode){
  //
}

struct node * remove_node(struct node *front, int data){
  //
}

int main(){
  struct node *list = NULL;
  //printf("test\n");
  printf("Printing empty list:\n");
  print_list(list);
  
  return 0;
}
