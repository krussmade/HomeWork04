#include "headers/container.h"

void errMessage1() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}


int main(int argc, char* argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    struct container c;
    init(&c);

    if (!strcmp(argv[1], "-f")) {
        FILE* in = fopen(argv[2], "r");
        fill(&c, in);
        fclose(in);
    }
    else if (!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        fillRnd(&c, size);
    }
    else {
        errMessage2();
        return 2;
    }

    FILE* out1 = fopen(argv[3], "w");
    FILE* out2 = fopen(argv[4], "w");
    fprintf(out1, "Filled container:\n");
    out(&c, out1);

    heapSort(&c);
    fprintf(out2, "Sorted container:\n");
    out(&c, out2);

    clear(&c);
    fclose(out1);
    fclose(out2);
    return 0;
}