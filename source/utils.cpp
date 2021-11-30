//
// Created by tagir on 30.11.2021.
//

#include "../headers/utils.h"

unsigned int XorRand() {
    static seed_t s;
    unsigned t = s.x ^ (s.x << 11);
    s.x = s.y;
    s.y = s.z;
    s.z = s.w;
    s.w = (s.w ^ (s.w >> 19)) ^ (t ^ (t >> 8));
    return s.w;
}

void randStr(char *src, int size) {
    const char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJMNOPQRSTUVWXYZ";
    const int length_alphabet = sizeof(alphabet) / sizeof(alphabet[0]);

    for (int i = 0; i < size; ++i) {
        src[i] = alphabet[XorRand() % length_alphabet];
    }
}