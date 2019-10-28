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

struct node * remove_node(struct node * firstnode, int data){
  //if data is the first node, just rmv it
  if (firstnode->i == data){
    struct node * newfirst = firstnode->next;
    free(firstnode);
    return newfirst;
  }else{
    struct node * this = firstnode->next;
    struct node * last = firstnode;
    //if data isn't first, find it and make the one b4 connect to the one after
    while(this != NULL){
      if (this-> i == data){
        last->next = this->next;
        free(this);
        return firstnode;
      }
      last = last->next;
      this = this->next;
    }
  }
  //data not in list
  return firstnode;
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

  printf("Removing 9:\n");
  list = remove_node(list,9);
  print_list(list);

  printf("Removing 4:\n");
  list = remove_node(list,4);
  print_list(list);

  printf("Removing 0:\n");
  list = remove_node(list,0);
  print_list(list);

  printf("Removing -1:\n");
  list = remove_node(list,-1);
  print_list(list);

  printf("Freeing list.\n");
  list = free_list(list);

  printf("Printing list:\n");
  //printf("%p\n", list);
  print_list(list);

  return 0;
}
