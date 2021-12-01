#include <stdlib.h>
#include "../headers/utils.h"

void randStr(char *src, int size) {
    for (int i = 0; i < size - 1; ++i) {
        src[i] = (char) ('a' + rand() % 26);
    }
    src[size] = '\0';
}
