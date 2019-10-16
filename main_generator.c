#include "./header/constantes.h"
#include "./header/generator.h"
#include "./header/mt19937ar.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Common Use : ./generator 100\n");
        return EXIT_FAILURE;
    }

    initialisationSeed();
    generateNumbersAndWriteIntoFile(atoi(argv[1]));

    return EXIT_SUCCESS;
}