#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct node {int i; struct node * next;};

void print_list(struct node * firstnode){
  printf("[ ");
  
  struct node * currentnode = firstnode;
  while (currentnode != NULL){
    printf("%d ", currentnode->i);
    currentnode = currentnode->next;
  }
  
  printf("]\n");
}

struct node * insert_front(struct node * firstnode, int data){
  struct node * new = malloc(sizeof(struct node));
  new->next = firstnode;
  new->i = data;

  return new;
}

struct node * free_list(struct node * firstnode){
  struct node * tempnode;
  struct node * currentnode = firstnode;

  while (currentnode != NULL){
    printf("freeing node: %d\n", currentnode->i);
    tempnode = currentnode->next;
    free(currentnode);
    currentnode = tempnode;
  }

  return currentnode;
}

struct node * remove_node(struct node *front, int data){
  //
}

int main(){
  struct node *list = NULL;
  //printf("test\n");
  printf("Printing empty list:\n");
  print_list(list);
  
  printf("Adding #s 0-9 to list.\n");
  int i;
  for(i = 0; i < 10; i++) {
      list = insert_front(list,i);
  }  

  printf("Printing list:\n");
  print_list(list);

  printf("Freeing list.\n");
  list = free_list(list);

  printf("Printing list:\n");
  //printf("%p\n", list);
  print_list(list);

  return 0;
}
