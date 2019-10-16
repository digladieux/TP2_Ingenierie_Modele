#include <stdio.h> 
#include <stdlib.h>

#include "./header/monte_carlo.h"
#include "./header/constantes.h"

int main(int argc, char ** argv)
{
    int nb_iterations, 
        nb_experiences ;
    char use_random_number_already_generated ;

    printf("MONTE CARLO ALGORITHM \n") ;
    printf("Enter a number of ITERATION and a number of EXPERIENCE\n") ;
    printf("The numbers have to be positive\n") ;
    printf("The multiplication of the 2 numbers has to be inferior at %d\n", MAX_ITERATION/2) ;


    do {
        scanf("%d", &nb_iterations) ;
        scanf("%d", &nb_experiences) ;
    } while ( (nb_iterations < 0) && (nb_experiences < 0) && (nb_experiences * nb_iterations > MAX_ITERATION/2) ) ;

    printf("Do you want to use numbers already generated or no ? \n") ;
    printf("y/n : ") ;

    do {
        use_random_number_already_generated = getchar() ;
    } while ( (use_random_number_already_generated != 'y') 
    && (use_random_number_already_generated != 'n') ) ;

    printf("You choose : \n");
    printf("Number of ITERATION : %d", nb_iterations) ;
    printf("\nNumber of EXPERIENCES : %d", nb_experiences) ;
    printf("\nNumber already generated : %c", use_random_number_already_generated) ;
    printf("\n") ;

    experiencesMonteCarlo(nb_experiences, nb_iterations, use_random_number_already_generated) ;

    return EXIT_SUCCESS ;
}