//
// Created by odmrs on 31/05/2025.

#include "./odmrsDsa/odmrsDsa.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
} LinkedList;

Node *createNode(int value) {
  Node *newNode = malloc(sizeof(Node));
  if (newNode == NULL) {
    return NULL;
  }

  newNode->next = NULL;
  newNode->value = value;

  return newNode;
}

void insertHead(LinkedList *ll, int value) {
  Node *newNode = createNode(value);

  newNode->next = ll->head;
  ll->head = newNode;
}

void printLinkedList(LinkedList *ll) {
  Node *cursor = ll->head;

  printf("Linked List: ");
  while (cursor != NULL) {
    printf("%d -> ", cursor->value);
    cursor = cursor->next;
  }

  printf("NULL;\n");
}

int main() {
  LinkedList *intList = (LinkedList *)malloc(sizeof(LinkedList));
  intList->head = NULL;
  insertHead(intList, 5);
  insertHead(intList, 5);
  insertHead(intList, 5);
  insertHead(intList, 5);
  insertHead(intList, 5);

  printLinkedList(intList);

  free(intList);
  return 0;
}