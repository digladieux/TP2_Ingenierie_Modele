/**
 * \file generator.c
 * \brief Fichier pour la generation de nombres aleatoires grace aux
 * generateurs Mercenne Twister
 * \author GLADIEUX CUNHA Dimitri
 * \date 17 Octobre 2019
 */

#include "../header/generator.h"
#include "../header/mt19937ar.h"

#include <stdio.h>

/**
 * \fn void generateNumbersAndWriteIntoFile(const unsigned int nb_numbers)
 * \brief Fonction generant n nombres reels aleatoires, et les sauvegardes dans
 * un fichier
 * \param nb_numbers Le nombre de nombre aleatoire que l'on veut
 * generer
 */
void generateNumbersAndWriteIntoFile(const long long int nb_numbers) {
    FILE* data_file = fopen("./data/data.c", "w");

    if (!data_file) {
        return;
    }

    fprintf(data_file, "unsigned long long int MAX_ITERATION = %lld;\n", nb_numbers);
    fputs("double random_numbers[] = {", data_file);

    if (nb_numbers > 0) {
        int i;
        for (i = 0; i < nb_numbers; i++) {
            fprintf(data_file, "%f,\n", genrand_real1());
        }
    }

    fputs("};", data_file);

    fclose(data_file);
}
