//
// Created by odmrs on 31/05/2025.

#include "./odmrsDsa/odmrsDsa.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
} LinkedList;

Node *createNode(int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    return NULL;
  }
  newNode->data = value;
  newNode->next = NULL;

  return newNode;
}

void insertHead(LinkedList *ll, int value) {
  Node *node = createNode(value);

  node->next = ll->head;
  ll->head = node;
}

void printLinkedList(LinkedList *ll) {
  printf("Linkedlist: ");
  Node *cursor = ll->head;
  while (cursor != NULL) {
    printf("%d -> ", cursor->data);
    cursor = cursor->next;
  }

  printf("NULL\n");
}

int linkedListIsEmpty(LinkedList *ll) {
  if (ll->head == NULL) {
    return 1;
  }

  return 0;
}

void insertNodeTail(LinkedList *ll, int value) {
  if (linkedListIsEmpty(ll)) {
    return;
  }
  Node *newNode = createNode(value);
  Node *cursor = ll->head;
  while (cursor->next != NULL) {
    cursor = cursor->next;
  }

  cursor->next = newNode;
  newNode->next = NULL;
}

void printReverseLinkedListUsingStack(LinkedList *ll) {
  if (linkedListIsEmpty(ll)) {
    printf("Reversed Linked list: NULL");
    return;
  }

  GenericStack *intStack = malloc(sizeof(GenericStack));
  init(intStack, sizeof(int));

  Node *cursor = ll->head;
  while (cursor != NULL) {
    push(intStack, &cursor->data);
    cursor = cursor->next;
  }

  printf("Reversed linked list: ");
  int out = 0;
  while (intStack->size != 0) {
    pop(intStack, &out);
    printf("%d -> ", out);
  }

  printf("NULL\n");
  destroy(intStack);
}

int main() {
  LinkedList *intList = (LinkedList *)malloc(sizeof(LinkedList));
  intList->head = NULL;
  insertHead(intList, 5);
  insertHead(intList, 4);
  insertHead(intList, 3);
  insertHead(intList, 2);
  insertHead(intList, 1);
  insertNodeTail(intList, 6);

  printLinkedList(intList);
  printReverseLinkedListUsingStack(intList);

  free(intList);
  return 0;
}