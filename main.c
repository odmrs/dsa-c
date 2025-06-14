//
// Created by odmrs on 31/05/2025.

#include "./odmrsDsa/odmrsDsa.h"
#include <stdlib.h>

int main() {
  LinkedList *intList = (LinkedList *)malloc(sizeof(LinkedList));
  intList->head = NULL;
  intList->tail = NULL;

  insertAtTailOptimized(intList, 6);
  insertAtTailOptimized(intList, 7);
  insertAtTailOptimized(intList, 8);

  printLinkedList(intList);

  destroyLinkedList(intList);
  return 0;
}