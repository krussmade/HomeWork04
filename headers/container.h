#ifndef ANIMALS_CONTAINER_H
#define ANIMALS_CONTAINER_H

#include "animal.h"

struct container {
    int count;
    struct animal *data[MAX_LEN];
};

void init(struct container *container);

void clear(struct container *container);

void fillRnd(struct container *container, int count);

void fill(struct container *container, FILE *in);

void out(struct container *container, FILE *out);

extern void swap(struct animal *a, struct animal *b);

extern void heapify(struct container *c, int n, int i);

extern void heapSort(struct container *container);

#endif //ANIMALS_CONTAINER_H
