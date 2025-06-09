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
// Utils

void myMemcpy(void *dst, const void *src, size_t size){
  char *cursorDst = (char *)dst;
  const char *cursorSrc = (char *)src;

  for (size_t i = 0; i < size; i++) {
    *cursorDst++ = *cursorSrc++;
  }
}

void myMemset(void *dst, int val, size_t size){
  unsigned char *cursor = dst;

  for (size_t i = 0; i < size; i++) {
    *(cursor + i) = (unsigned char)val;
  }
}
