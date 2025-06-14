//
// Created by odmrs on 31/05/2025.
//

#include "odmrsDsa.h"

#include <stdio.h>
#include <stdlib.h>
// Stack
void init(GenericStack *gs, size_t stackTypeSize) {
  gs->size = 0;
  gs->capacity = 2;
  gs->sizeActualType = stackTypeSize;
  gs->alreadyAllocated = 0;

  void *tmp = calloc(gs->capacity, stackTypeSize);
  if (tmp == NULL) {
    return;
  }

  gs->data = tmp;
}

void destroy(GenericStack *gs) {
  free(gs->data);
  free(gs);
}

void push(GenericStack *gs, const void *value) {
  if (gs->size == gs->capacity) {
    gs->capacity *= 2;
    void *tmp = realloc(gs->data, gs->capacity * gs->sizeActualType);
    if (tmp == NULL) {
      return;
    }

    gs->data = tmp;
  }

  myMemcpy((char *)gs->data + gs->size * gs->sizeActualType, value,
           gs->sizeActualType);

  gs->size++;
}

void *pop(GenericStack *gs, void *out) {
  if (gs->size == 0) {
    printf("Stack empty");
    if (gs->alreadyAllocated) {
      return NULL;
    }
    gs->capacity = 2;
    void *tmp = realloc(gs->data, gs->capacity * gs->sizeActualType);
    if (tmp == NULL) {
      return NULL;
    }

    gs->data = tmp;
    gs->alreadyAllocated = 1;
    return NULL;
  }

  myMemcpy(out, (char *)gs->data + (gs->size - 1) * gs->sizeActualType,
           gs->sizeActualType);
  myMemset((char *)gs->data + (gs->size - 1) * gs->sizeActualType, 0,
           gs->sizeActualType);

  gs->size--;
  gs->alreadyAllocated = 0;
  return out;
}

// ----------------------------------------------------------------------------;

// Queue

void initQueue(GenericQueue *gq, size_t typeOfQueue) {
  gq->capacity = 2;
  gq->head = 0;
  gq->tail = 0;
  gq->size = 0;
  gq->typeSize = typeOfQueue;

  void *tmp = calloc(gq->capacity, typeOfQueue);
  if (tmp == NULL) {
    return;
  }

  gq->data = tmp;
}

void reorgQueue(GenericQueue *gq, int oldCap) {
  gq->capacity *= 2;
  void *tmp = calloc(gq->capacity, gq->typeSize);
  if (tmp == NULL) {
    return;
  }

  for (int i = 0; i < gq->size; i++) {
    const int realIndex = (gq->head + i) % oldCap;
    const char *src = (const char *)gq->data + realIndex * gq->typeSize;
    char *dest = (char *)tmp + i * gq->typeSize;

    myMemcpy(dest, src, gq->typeSize);
  }

  free(gq->data);
  gq->data = tmp;
  gq->head = 0;
  gq->tail = gq->size;
}

void enqueue(GenericQueue *gq, int *value) {
  if (gq->size == gq->capacity) {
    reorgQueue(gq, gq->capacity);
  }

  myMemcpy((char *)gq->data + gq->tail * gq->typeSize, value, gq->typeSize);

  gq->tail = (gq->tail + 1) % gq->capacity;
  gq->size++;
}

int isQueueEmpty(GenericQueue *gq) {
  if (gq->size == 0) {
    return 1;
  }

  return 0;
}

void *dequeue(GenericQueue *gq, void *out) {
  if (isQueueEmpty(gq)) {
    return NULL;
  }

  myMemcpy(out, (char *)gq->data + gq->head * gq->typeSize, gq->typeSize);

  gq->head = (gq->head + 1) % gq->capacity;
  gq->size--;

  return out;
}

void destroyQueue(GenericQueue *gq) {
  free(gq->data);
  free(gq);
}
// ----------------------------------------------------------------------------;

// Linked List

Node *createNode(int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    return NULL;
  }
  newNode->data = value;
  newNode->next = NULL;

  return newNode;
}

void insertAtHead(LinkedList *ll, int value) {
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

int isLinkedListEmpty(LinkedList *ll) {
  if (ll->head == NULL) {
    return 1;
  }

  return 0;
}

void insertAtTail(LinkedList *ll, int value) {
  if (isLinkedListEmpty(ll)) {
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

void printReverseUsingStack(LinkedList *ll) {
  if (isLinkedListEmpty(ll)) {
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

void printReverseUsingRecursion(Node *no) {
  recursionLinkedList(no);
  printf("NULL\n");
}

void insertAtTailOptimized(LinkedList *ll, int value) {
  Node *newNode = createNode(value);
  if (newNode == NULL) {
    return;
  }

  if (isLinkedListEmpty(ll)) {
    ll->head = newNode;
    ll->tail = newNode;
  } else {
    ll->tail->next = newNode;
    ll->tail = newNode;
  }
}

Node *findNodeByValue(LinkedList *ll, int searchValue) {
  if (isLinkedListEmpty(ll)) {
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

  if (isLinkedListEmpty(ll)) {
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
  if (isLinkedListEmpty(ll)) {
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

int destroyLinkedList(LinkedList *ll) {
  Node *cursor = ll->head;

  while (cursor != NULL) {
    Node *next = cursor->next;
    free(cursor);
    cursor = next;
  }

  free(ll);
  ll->head == NULL;
  ll->tail == NULL;
  return 1;
}

// ----------------------------------------------------------------------------;

// Utils

void myMemcpy(void *dst, const void *src, size_t size) {
  char *cursorDst = (char *)dst;
  const char *cursorSrc = (char *)src;

  for (size_t i = 0; i < size; i++) {
    *cursorDst++ = *cursorSrc++;
  }
}

void myMemset(void *dst, int val, size_t size) {
  unsigned char *cursor = dst;

  for (size_t i = 0; i < size; i++) {
    *(cursor + i) = (unsigned char)val;
  }
}
