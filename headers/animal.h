//
// Created by tagir on 30.11.2021.
//

#ifndef ANIMALS_ANIMAL_H
#define ANIMALS_ANIMAL_H

#include <cstdio>
#include "constants.h"
#include "utils.h"

struct beast {
    enum Diet {
        PREDATOR = 0,
        HERBIVOROUS = 1,
        INSECTIVORES = 2
    };
    Diet diet;
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
    };
    Habitat habitat;
};

struct animal {
    enum key {
        FISH = 0, BIRD = 1, BEAST = 2
    };
    union {
        fish someFish;
        bird someBird;
        beast someBeast;
    };
    char name[NAME_SIZE];
    int weight;
    key k;
};

animal *readAnimal(FILE *in);

animal *fillAnimal();

void outAnimal(animal *a, FILE *out);

extern double someParameter(animal *someAnimal);

#endif //ANIMALS_ANIMAL_H
