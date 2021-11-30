//
// Created by tagir on 29.11.2021.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "../headers/animal.h"


animal *readAnimal(FILE *in) {
    animal *a;

    char type[NAME_SIZE];
    char name[NAME_SIZE];
    int weight;
    fscanf(in, "%s\n", type);

    if (!strcmp(type, "fish")) {
        int habitat;
        fscanf(in, "%s %d %d\n", name, &weight, &habitat);
        a = new animal;
        a->k = animal::FISH;
        a->someFish.habitat = (fish::Habitat) habitat;
        a->weight = weight;
        for (int i = 0; i < NAME_SIZE; ++i) {
            a->name[i] = name[i];
        }
        return a;
    } else if (!strcmp(type, "beast")) {
        int diet;
        fscanf(in, "%s %d %d\n", name, &weight, &diet);
        a = new animal;
        a->k = animal::BEAST;
        a->someBeast.diet = (beast::Diet) diet;
        a->weight = weight;
        for (int i = 0; i < NAME_SIZE; ++i) {
            a->name[i] = name[i];
        }
        return a;
    } else if (!strcmp(type, "bird")) {
        int is_migration;
        fscanf(in, "%s %d %d\n", name, &weight, &is_migration);
        a = new animal;
        a->k = animal::BIRD;
        a->someBird.is_migration = (bool) is_migration;
        a->weight = weight;
        for (int i = 0; i < NAME_SIZE; ++i) {
            a->name[i] = name[i];
        }
        return a;
    } else {
        printf("ERROR: Wrong animal type %s\n", type);
        exit(1);
    }
}

animal *fillAnimal() {
    animal *a;
    auto k = XorRand() % 3;
    switch (k) {
        case 0:
            a = new animal;
            a->k = animal::FISH;
            a->weight = XorRand() % 100 + 10;
            randStr(a->name, NAME_SIZE);
            a->someFish.habitat = (fish::Habitat) (XorRand() % 5);
            return a;
        case 1:
            a = new animal;
            a->k = animal::BIRD;
            a->weight = XorRand() % 10 + 10;
            randStr(a->name, NAME_SIZE);
            a->someBird.is_migration = (bool) (XorRand() % 2);
            return a;
        case 2:
            a = new animal;
            a->k = animal::BEAST;
            a->weight = XorRand() % 100 + 10;
            randStr(a->name, NAME_SIZE);
            a->someBeast.diet = (beast::Diet) (XorRand() % 3);
            return a;
        default:
            return nullptr;
    }
}

//double someParameter(animal *someAnimal) {
//    int sum = 0;
//    for (int i = 0; i < NAME_SIZE; ++i) {
//        if (someAnimal->name[i] == '\0') {
//            break;
//        }
//        sum += (int) someAnimal->name[i];
//    }
//    return sum / (double) someAnimal->weight;
//}

void outAnimal(animal *a, FILE *out) {
    switch (a->k) {
        case animal::FISH:
            fprintf(out, "[Fish]\n"
                         "-name: %s\n"
                         "-weight: %d\n"
                         "-habitat %d\n"
                         "-function result: %lf\n\n",
                    a->name,
                    a->weight,
                    (int) a->someFish.habitat,
                    someParameter(a));
            break;
        case animal::BIRD:
            fprintf(out, "[Bird]\n"
                         "-name: %s\n"
                         "-weight: %d\n"
                         "-migration %d\n"
                         "-function result: %lf\n\n",
                    a->name,
                    a->weight,
                    (int) a->someBird.is_migration,
                    someParameter(a));
            break;
        case animal::BEAST:
            fprintf(out, "[Beast]\n"
                         "-name: %s\n"
                         "-weight: %d\n"
                         "-diet %d\n"
                         "-function result: %lf\n\n",
                    a->name,
                    a->weight,
                    (int) a->someBeast.diet,
                    someParameter(a));
            break;
    }
}