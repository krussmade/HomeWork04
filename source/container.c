#include "../headers/container.h"

void init(struct container *container) {
    container->count = 0;
}

void clear(struct container *container) {
    for (int i = 0; i < container->count; ++i) {
        free(container->data[i]);
    }
    container->count = 0;
}

void fillRnd(struct container *container, int count) {
    for (int i = 0; i < count; ++i) {
        if ((container->data[container->count] = fillAnimal()) != NULL) {
            container->count++;
        }
    }
}

void fill(struct container *container, FILE *in) {
    while (!feof(in)) {
        if (MAX_LEN <= container->count) {
            return;
        }
        if ((container->data[container->count] = readAnimal(in)) != NULL) {
            container->count++;
        }
    }
}

void out(struct container *container, FILE *out) {
    for (int i = 0; i < container->count; i++) {
        fprintf(out, "%d. ", (i + 1));
        outAnimal(container->data[i], out);
    }
}

//void swap(struct animal *a, struct animal *b) {
//    struct animal t = *a;
//    *a = *b;
//    *b = t;
//}
//
//void heapify(struct container *c, int n, int i) {
//    int largest = i;
//    int l = 2 * i + 1;
//    int r = 2 * i + 2;
//
//    if (l < n && someParameter((*c).data[l]) > someParameter((*c).data[largest]))largest = l;
//    if (r < n && someParameter((*c).data[r]) > someParameter((*c).data[largest]))largest = r;
//
//    if (largest != i) {
//        swap((*c).data[i], (*c).data[largest]);
//        heapify(c, n, largest);
//    }
//}
//
//void heapSort(struct container *c) {
//    int n = c->count;
//    for (int i = n / 2 - 1; i >= 0; i--)
//        heapify(c, n, i);
//
//    for (int i = n - 1; i >= 0; i--) {
//        swap((*c).data[0], (*c).data[i]);
//        heapify(c, i, 0);
//    }
//}