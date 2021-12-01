#include "../headers/animal.h"


struct animal *readAnimal(FILE *in) {
    struct animal *a;

    char type[NAME_SIZE];
    char name[NAME_SIZE];
    int weight;
    fscanf(in, "%s\n", type);

    if (!strcmp(type, "fish")) {
        int habitat;
        fscanf(in, "%s %d %d\n", name, &weight, &habitat);
        a = malloc(sizeof(struct animal));
        a->k = FISH;
        a->someFish.habitat = habitat;
        a->weight = weight;
        for (int i = 0; i < NAME_SIZE; ++i) {
            a->name[i] = name[i];
        }
        return a;
    } else if (!strcmp(type, "beast")) {
        int diet;
        fscanf(in, "%s %d %d\n", name, &weight, &diet);
        a = malloc(sizeof(struct animal));
        a->k = BEAST;
        a->someBeast.diet = diet;
        a->weight = weight;
        for (int i = 0; i < NAME_SIZE; ++i) {
            a->name[i] = name[i];
        }
        return a;
    } else if (!strcmp(type, "bird")) {
        int is_migration;
        fscanf(in, "%s %d %d\n", name, &weight, &is_migration);
        a = malloc(sizeof(struct animal));
        a->k = BIRD;
        a->someBird.is_migration = is_migration;
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

struct animal *fillAnimal() {
    struct animal *a;
    int k = XorRand() % 3;
    switch (k) {
        case 0:
            a = malloc(sizeof(struct animal));
            a->k = FISH;
            a->weight = XorRand() % 100 + 10;
            randStr(a->name, NAME_SIZE);
            a->someFish.habitat = (XorRand() % 5);
            return a;
        case 1:
            a = malloc(sizeof(struct animal));
            a->k = BIRD;
            a->weight = XorRand() % 10 + 10;
            randStr(a->name, NAME_SIZE);
            a->someBird.is_migration = (XorRand() % 2);
            return a;
        case 2:
            a = malloc(sizeof(struct animal));
            a->k = BEAST;
            a->weight = XorRand() % 100 + 10;
            randStr(a->name, NAME_SIZE);
            a->someBeast.diet = (XorRand() % 3);
            return a;
        default:
            return NULL;
    }
}

//double someParameter(struct animal *someAnimal) {
//    int sum = 0;
//    for (int i = 0; i < NAME_SIZE; ++i) {
//        if (someAnimal->name[i] == '\0') {
//            break;
//        }
//        sum += (int) someAnimal->name[i];
//    }
//    return sum / (double) someAnimal->weight;
//}

void outAnimal(struct animal *a, FILE *out) {
    switch (a->k) {
        case FISH:
            fprintf(out, "[Fish]\n"
                         "-name: %s\n"
                         "-weight: %d\n"
                         "-habitat %d\n"
                         "-function result: %lf\n\n",
                    a->name,
                    a->weight,
                    a->someFish.habitat,
                    someParameter(a));
            break;
        case BIRD:
            fprintf(out, "[Bird]\n"
                         "-name: %s\n"
                         "-weight: %d\n"
                         "-migration %d\n"
                         "-function result: %lf\n\n",
                    a->name,
                    a->weight,
                    a->someBird.is_migration,
                    someParameter(a));
            break;
        case BEAST:
            fprintf(out, "[Beast]\n"
                         "-name: %s\n"
                         "-weight: %d\n"
                         "-diet %d\n"
                         "-function result: %lf\n\n",
                    a->name,
                    a->weight,
                    a->someBeast.diet,
                    someParameter(a));
            break;
    }
}