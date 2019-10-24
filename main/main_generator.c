/**
 * \file main_generator.c
 * \brief Fichier principale de l'executable generator
 * \author GLADIEUX CUNHA Dimitri
 * \date 17 octobre 2019
 */

#include "../header/generator.h"
#include "../header/mt19937ar.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * \fn int main(int argc, char** argv)
 * \brief Fonction principale de notre programme. On va generer n nombres aleatoires suivant le parametre en ligne de commande
 * \param argc Nombre de parametres en ligne de commande
 * \param argv Tableau de caracteres contenant le nombre de nombre que l'on souhaite generer
 * \return Code erreur retourne par l'application
 */
int main(int argc, char** argv) {
    long long int nb_number ;

    if (argc != 2) {
        puts("Common Use : ./generator 100\n");
        return EXIT_FAILURE;
    }

    if (sscanf(argv[1], "%lld", &nb_number) != 1) {
        puts("Error: The parameter has to be a number\n");
        return EXIT_FAILURE;
    }

    if (nb_number < 0) {
        puts("Error : The number has to be positif") ;
    }

    initialisationSeed();
    generateNumbersAndWriteIntoFile(nb_number);
    
    return EXIT_SUCCESS;
}