#ifndef ANIMALS_ANIMAL_H
#define ANIMALS_ANIMAL_H
#include <string.h>
#include <stdlib.h>
#include "stdio.h"
#include "constants.h"
#include "utils.h"

struct beast {
    enum Diet {
        PREDATOR = 0,
        HERBIVOROUS = 1,
        INSECTIVORES = 2
    } diet;
};

struct bird {
    bool is_migration;
};

struct fish {
    enum Habitat {
        SEA = 0,
        LAKE = 1,
        RIVER = 2,
        OCEAN = 3,
        POND = 4
    } habitat;
};

struct animal {
    enum key {
        FISH = 0, BIRD = 1, BEAST = 2
    } k;
    union {
        struct fish someFish;
        struct bird someBird;
        struct beast someBeast;
    };
    char name[NAME_SIZE];
    int weight;
};

struct animal *readAnimal(FILE *in);

struct animal *fillAnimal();

void outAnimal(struct animal *a, FILE *out);

extern double someParameter(struct animal *someAnimal);

#endif //ANIMALS_ANIMAL_H
