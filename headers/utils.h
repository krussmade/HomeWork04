#ifndef ANIMALS_UTILS_H
#define ANIMALS_UTILS_H

struct seed_t {
    unsigned x = 1; // начальные значения могут быть любыми
    unsigned y = 123;
    unsigned z = 456;
    unsigned w = 768;
};

unsigned int XorRand();

void randStr(char *src, int size);

#endif //ANIMALS_UTILS_H
