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

#endif
