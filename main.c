//
// Created by odmrs on 31/05/2025.

#include "odmrsDsa/odmrsDsa.h"
#include <stdlib.h>

int main() {
  GenericStack *floatStack = malloc(sizeof(GenericStack));
  if (floatStack == NULL) {
    return -1;
  }

  float floatList[] = {1.0f, 3.0f, 4.0f, 5.0f};

  init(floatStack, sizeof(float));
  push(floatStack, &floatList[0]);
  push(floatStack, &floatList[1]);
  push(floatStack, &floatList[2]);
  push(floatStack, &floatList[3]);

  float out = 0.0f;
  pop(floatStack, &out);
  pop(floatStack, &out);
  pop(floatStack, &out);
  pop(floatStack, &out);
  pop(floatStack, &out);
  pop(floatStack, &out);

  push(floatStack, &floatList[0]);
  push(floatStack, &floatList[1]);
  push(floatStack, &floatList[2]);
  push(floatStack, &floatList[3]);

  destroy(floatStack);
}