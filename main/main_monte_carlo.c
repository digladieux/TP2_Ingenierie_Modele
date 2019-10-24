/**
 * \file main_monte_carlo.c
 * \brief Fichier principale de l'executable monte_carlo
 * \author GLADIEUX CUNHA Dimitri
 * \date 17 octobre 2019
 */

#include <stdio.h> 
#include <stdlib.h>

#include "../header/monte_carlo.h"

/**
 * \fn int main(int argc, char** argv)
 * \brief Fonction principale de notre programme. L'utilisateur choisit le nombre d'experiences et d'iterations de Monte Carlo.
 * Il choisit aussi si la generation se fait avec des nombres reels pre-calcule ou non.
 * \param argc Nombre de parametres en ligne de commande
 * \param argv Tableau de caracteres contenant le nom de l'executable
 * \return Code erreur retourne par l'application
 */

extern long long int MAX_ITERATION ; 
void menu();

int main(int argc, char ** argv)
{
    if (argc == 1) {
        menu() ;
        return EXIT_SUCCESS ;
    }

    char use_random_number_already_generated = argv[1][0] ;

    if (argc == 2 && (use_random_number_already_generated == 'y' || use_random_number_already_generated == 'n')) {
        calcTime(use_random_number_already_generated) ; 
        return EXIT_SUCCESS ;
    }
    return EXIT_FAILURE ;
}

void menu() {
    long long int nb_iterations, 
        nb_experiences ;
    char use_random_number_already_generated ;
    printf("\nMONTE CARLO ALGORITHM \n\n") ;
    printf("Enter a number of ITERATION and a number of EXPERIENCE\n") ;
    printf("- The numbers have to be positive\n") ;
    printf("- The multiplication of the 2 numbers has to be inferior at %lld if you use number already generated\n", MAX_ITERATION/2) ;


    do {
        scanf("%lld", &nb_iterations) ;
        scanf("%lld", &nb_experiences) ;
    } while ( (nb_iterations < 0) && (nb_experiences < 0) && (nb_experiences * nb_iterations > MAX_ITERATION/2) ) ;

    printf("Do you want to use numbers already generated or no ? \n") ;
    printf("y/n : ") ;

    do {
        use_random_number_already_generated = getchar() ;
    } while ( (use_random_number_already_generated != 'y') 
    && (use_random_number_already_generated != 'n') ) ;

    printf("\nYou choose : \n");
    printf("Number of ITERATION : %lld", nb_iterations) ;
    printf("\nNumber of EXPERIENCES : %lld", nb_experiences) ;
    printf("\nNumber already generated : %c", use_random_number_already_generated) ;
    printf("\n") ;

    experiencesMonteCarlo(nb_experiences, nb_iterations, use_random_number_already_generated) ;

}