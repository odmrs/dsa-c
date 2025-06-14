//
// Created by odmrs on 31/05/2025.
//

#ifndef ODMRSDSA_H
#define ODMRSDSA_H

#include <stddef.h>

// Stack
typedef struct {
  void *data;
  int size;
  int capacity;
  size_t sizeActualType;
  int alreadyAllocated;
} GenericStack;

void init(GenericStack *gs, size_t typeSize);
void destroy(GenericStack *gs);
void push(GenericStack *gs, const void *value);
void *pop(GenericStack *gs, void *out);
// ----------------------------------------------- ;

// Queue
typedef struct {
  void *data;
  size_t typeSize;
  int size;
  int capacity;

  int head;
  int tail;
} GenericQueue;

void initQueue(GenericQueue *gq, size_t typeOfQueue);
void reorgQueue(GenericQueue *gq, int oldCap);
void enqueue(GenericQueue *gq, int *value);
int isQueueEmpty(GenericQueue *gq);
void *dequeue(GenericQueue *gq, void *out);
void destroyQueue(GenericQueue *gq);

// ----------------------------------------------- ;

// Linked List
typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
  Node *tail;
} LinkedList;

// Core LinkedList functions
Node *createNode(int value);
void insertAtHead(LinkedList *ll, int value);
void insertAtTail(LinkedList *ll, int value);
void insertAtTailOptimized(LinkedList *ll, int value);
int removeNodeByValue(LinkedList *ll, int target);
int removeTail(LinkedList *ll);
Node *findNodeByValue(LinkedList *ll, int searchValue);
int isLinkedListEmpty(LinkedList *ll);
void printLinkedList(LinkedList *ll);
void printReverseUsingStack(LinkedList *ll);
void printReverseUsingRecursion(Node *node);
int destroyLinkedList(LinkedList *ll);

// ----------------------------------------------- ;

// UTILS
void myMemcpy(void *dst, const void *src, size_t size);
void myMemset(void *dst, int val, size_t size);

#endif

// ----------------------------------------------- ;
