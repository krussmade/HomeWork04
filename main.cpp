#include <cstring>
#include <cstdlib>
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


int main(int argc, char *argv[]) {
//    if (argc != 5) {
//        errMessage1();
//        return 1;
//    }

    container c;
    init(&c);

//    if (!strcmp(argv[1], "-f")) {
//        FILE *in = fopen(argv[2], "r");
//        fill(&c, in);
//        fclose(in);
//    } else if (!strcmp(argv[1], "-n")) {
//        int size = atoi(argv[2]);
//        fill(&c, size);
//    } else {
//        errMessage2();
//        return 2;
//    }

    FILE *in = fopen("C:\\Users\\tagir\\Desktop\\a.txt", "r");
    fill(&c, in);
    fclose(in);

    FILE *out1 = fopen("C:\\Users\\tagir\\Desktop\\b.txt", "w");
    FILE *out2 = fopen("C:\\Users\\tagir\\Desktop\\c.txt", "w");
    fprintf(out1, "Filled container:\n");
    out(&c, out1);

    heapSort(&c);
    fprintf(out2, "Sorted container:\n");
    out(&c, out2);

    clear(&c);
    return 0;
}