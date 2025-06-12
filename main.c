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
  Node *tail;
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
    printf("%d[%p] -> ", cursor->data, cursor);
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

void recursionLinkedList(Node *no) {
  if (no == NULL) {
    return;
  }

  recursionLinkedList(no->next);
  printf("%d -> ", no->data);
}

void printReverseLinkedListUsingRecursion(Node *no) {
  recursionLinkedList(no);
  printf("NULL\n");
}

void insertTailOdNLinkedList(LinkedList *ll, int value) {
  Node *newNode = createNode(value);
  if (newNode == NULL) {
    return;
  }

  if (linkedListIsEmpty(ll)) {
    ll->head = newNode;
    ll->tail = newNode;
  } else {
    ll->tail->next = newNode;
    ll->tail = newNode;
  }
}

Node *findNodeByValueLinkedList(LinkedList *ll, int searchValue) {
  if (linkedListIsEmpty(ll)) {
    return NULL;
  }

  Node *cursor = ll->head;
  while (cursor != NULL) {
    if (cursor->data == searchValue) {
      return cursor;
    }

    cursor = cursor->next;
  }

  return cursor;
}

int main() {
  LinkedList *intList = (LinkedList *)malloc(sizeof(LinkedList));
  intList->head = NULL;
  intList->tail = NULL;

  insertTailOdNLinkedList(intList, 6);
  insertTailOdNLinkedList(intList, 7);
  insertTailOdNLinkedList(intList, 8);
  Node *foundedNode = findNodeByValueLinkedList(intList, 6);
  if (foundedNode == NULL) {
    printf("No node founded with this value");
    return -1;
  }

  printLinkedList(intList);
  printf("Node founded getting the value 6 -> data: %d | address: %p\n",
         foundedNode->data, foundedNode);
  free(intList);
  free(foundedNode);
  return 0;
}