#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct node {char * name; struct node * next;};

void print_list(struct node * firstnode){
  struct node * currentnode = firstnode;
  while (currentnode.next != '\0'){
    //
  }
}

struct node * insert_front(struct node * firstnode, int i){
  //
}

struct node * free_list(struct node * firstnode){
  //
}

struct node * remove_node(struct node *front, int data){
  //
}

int main(){
    srand(time(NULL));

    return 0;
}
