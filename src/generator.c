#include "../header/generator.h"
#include "../header/mt19937ar.h"
#include <stdio.h>
void generateNumbersAndWriteIntoFile(const unsigned int nb_numbers) {
    int i;
    FILE * fichier = fopen("./data/data.c", "w") ;

    if (!fichier)
    {
        return ;
    } 

    fputs("const double random_numbers[] = {", fichier);

    for (i = 0; i < nb_numbers ; i++) {
        fprintf(fichier, "%f,",genrand_real1());
    }

    fputs("};", fichier);
    
    fclose(fichier) ;
}   
