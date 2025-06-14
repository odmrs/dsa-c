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

int removeNodeByValue(LinkedList *ll, int target) {
  Node *cursor = ll->head;

  if (linkedListIsEmpty(ll)) {
    printf("Linked list is emtpy");
    return 0;
  }

  if (cursor->data == target) {
    Node *toRemove = ll->head;
    ll->head = toRemove->next;
    free(toRemove);
    return 1;
  }

  while (cursor->next != NULL) {
    if (cursor->next->data == target) {
      Node *toRemove = cursor->next;
      cursor->next = toRemove->next;

      free(toRemove);
      return 1;
    }

    cursor = cursor->next;
  }

  printf("Value not found \n");

  return 0;
}

int removeTail(LinkedList *ll) {
  if (linkedListIsEmpty(ll)) {
    printf("Linked list is empty");
    return 0;
  }

  Node *cursor = ll->head;

  // Verify if the first already is the tail
  if (cursor->next == NULL) {
    ll->head = NULL;
    return 1;
  }

  while (cursor->next->next != NULL) {
    cursor = cursor->next;
  }

  Node *toRemove = cursor->next;
  cursor->next = NULL;
  free(toRemove);

  return 1;
}

int main() {
  LinkedList *intList = (LinkedList *)malloc(sizeof(LinkedList));
  intList->head = NULL;
  intList->tail = NULL;

  insertTailOdNLinkedList(intList, 6);
  insertTailOdNLinkedList(intList, 7);
  insertTailOdNLinkedList(intList, 8);

  printLinkedList(intList);

  // removeNodeByValue(intList, 8);
  removeTail(intList);
  printLinkedList(intList);

  free(intList);
  return 0;
}