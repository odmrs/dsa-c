//
// Created by odmrs on 31/05/2025.

#include "./odmrsDsa/odmrsDsa.h"
#include <stdio.h>
#include <stdlib.h>

void print_int(void *p) { printf("%d", *(int *)p); }
void print_queue(GenericQueue *gq, void (*print_fn)(void *)) {
  printf("Queue (size=%d, cap=%d): [", gq->size, gq->capacity);
  for (int i = 0; i < gq->size; i++) {
    int index = (gq->head + i) % gq->capacity;
    if (i > 0)
      printf(", ");
    print_fn((char *)gq->data + index * gq->typeSize);
  }
  printf("]\n");
}

int main() {
  GenericQueue *gqInt =
      (GenericQueue *)calloc(sizeof(GenericQueue), sizeof(int));
  initQueue(gqInt, sizeof(int));
  int values[] = {3, 4, 1, 8, 2};
  int outInt = 0;

  enqueue(gqInt, &values[0]);
  print_queue(gqInt, print_int);
  enqueue(gqInt, &values[1]);
  print_queue(gqInt, print_int);
  dequeue(gqInt, &outInt);
  printf("Dequeued: %d\n", outInt);
  print_queue(gqInt, print_int);
  enqueue(gqInt, &values[2]);
  print_queue(gqInt, print_int);
  enqueue(gqInt, &values[3]);
  print_queue(gqInt, print_int);
  dequeue(gqInt, &outInt);
  printf("Dequeued: %d\n", outInt);
  print_queue(gqInt, print_int);
  enqueue(gqInt, &values[4]);
  print_queue(gqInt, print_int);
  destroyQueue(gqInt);
}