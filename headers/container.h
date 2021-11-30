//
// Created by tagir on 29.11.2021.
//

#ifndef ANIMALS_CONTAINER_H
#define ANIMALS_CONTAINER_H

#include "animal.h"

struct container {
    int count;
    animal *data[MAX_LEN];
};

void init(container *container);

void clear(container *container);

void fill(container *container, int count);

void fill(container *container, FILE *in);

void out(container *container, FILE *out);

extern void swap(animal *a, animal *b);

extern void heapify(container *c, int n, int i);

extern void heapSort(container *container);

#endif //ANIMALS_CONTAINER_H
