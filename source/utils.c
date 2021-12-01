#include "../headers/utils.h"

static unsigned x = 1;
static unsigned y = 123;
static unsigned z = 456;
static unsigned w = 768;

unsigned int XorRand() {
    unsigned int t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    return w;
}

void randStr(char *src, int size) {
    const char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJMNOPQRSTUVWXYZ";
    const int length_alphabet = sizeof(alphabet) / sizeof(alphabet[0]);

    for (int i = 0; i < size - 1; ++i) {
        src[i] = alphabet[XorRand() % length_alphabet];
    }
    src[size - 1] = '\0';
}
