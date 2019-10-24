/**
 * \file monte_carlo.c
 * \brief Fichier pour l'algorithme de Monte Carlo
 * \author GLADIEUX CUNHA Dimitri
 * \date 17 Octobre 2019
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include "../header/monte_carlo.h"
#include "../header/mt19937ar.h"

/**
 * \brief Tableaux de nombres aleatoire deja genere
 */
extern double random_numbers[];
extern long long int MAX_ITERATION ; 

void isPointInsideCircle(double x, double y, unsigned long long int* count) ;
int Question7() {

    char * file_name = "./data/mappedFile.txt" ;
    struct stat st ;
    stat(file_name, &st) ;
    int fd = open(file_name, O_RDONLY, S_IRUSR) ;
    if (fd == -1) {
        return EXIT_FAILURE ;
    }

    double* mmappedData = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0) ;

    if (mmappedData == MAP_FAILED) {
        return EXIT_FAILURE ;
    }
    
    int i ;
    for (i = 0 ; i < st.st_size ; i ++) {
        printf("%lf",mmappedData[i]) ;
    }
    int rc = munmap(mmappedData, st.st_size) ;
    if (rc != 0) {
        return EXIT_FAILURE ;
    }
    close(fd) ;
    return EXIT_SUCCESS;
}

/**
 * \fn void calcTime(char use_random_number_already_generated)
 * \brief Calcul du temps pour la question 5 de lire dans un tableau ou de generer des nombres aleatoires
 * \param use_random_number_already_generated Utiliser les nombres deja generer ou non
 */
void calcTime(char use_random_number_already_generated) {
    int i = 0 ;
    if (use_random_number_already_generated == 'y') {
        for (i ; i < MAX_ITERATION ; i++) {
            random_numbers[i];
        }
    }
    else if (use_random_number_already_generated == 'n') {
        for (i ; i < MAX_ITERATION ; i++) {
            genrand_real2();
        }
    }
}
/**
 * \fn void experiencesMonteCarlo(const int nb_experiences, const int
 * nb_iterations, char use_random_number_already_generated) \brief Methode
 * effectuant n experiences de Monte Carlo, avec m iterations. On definit si on
 * souhaite utiliser des nombres deja genere ou non. On calcul aussi l'ecart a
 * la moyenne entre les resultats experimentaux du calcul de PI et la valeur
 * theorique de ce dernier \param nb_experiences Le nombre d'experiences que
 * l'on desire \param nb_iterations Le nombre d'iterations que l'on souhaite
 * \param use_random_number_already_generated Boolean qui indique si on utilise
 * les nombres deja genere ou non
 */
void experiencesMonteCarlo(const long long int nb_experiences, const long long int nb_iterations,
                           char use_random_number_already_generated) {
    unsigned int i;
    double average_gap = 0;

    if ((use_random_number_already_generated != 'y') &&
            (use_random_number_already_generated != 'n') ||
        (nb_experiences < 0) || (nb_iterations < 0)) {
        return;
    }

    for (i = 0; i < nb_experiences; i++) {
        double pi = monteCarlo(i * nb_iterations, (i + 1) * nb_iterations,
                               use_random_number_already_generated);
        double tmp = M_PI - pi;
        average_gap += tmp < 0 ? tmp * (-1) : tmp;
        printf("%u Step - Value of Pi : %f\n", i + 1, pi);
    }

    average_gap /= nb_experiences;
    printf("Average Gap : %f\n", average_gap);
}

/**
 * \fn double monteCarlo(const int begin, const int end, char
 * use_random_number_already_generated) \brief Fonction effectuant une
 * experience de Monte Carlo, avec m iterations. On definit si on souhaite
 * utiliser des nombres deja genere ou non \param begin Le debut du tableau de
 * nombre aleatoires \param end La fin du tableau de nombre aleatoires \param
 * use_random_number_already_generated Boolean qui indique si on utilise les
 * nombres deja genere ou non \return La valeur experimentale de PI.
 */
double monteCarlo(const long long int begin, const long long int end,
                  char use_random_number_already_generated) {
    double x, y;
    unsigned long long int nb_iterations = end - begin, i = begin;
    unsigned long long int count = 0;

    if (begin < 0 || end < 0 ||
        (end > MAX_ITERATION && use_random_number_already_generated == 'y') ||
        (use_random_number_already_generated != 'y') &&
            (use_random_number_already_generated != 'n')) {
        return EXIT_FAILURE;
    }

    if (use_random_number_already_generated != 'n') {
        for (i = begin; i < begin + nb_iterations * 2; i += 2) {
            x = random_numbers[i];
            y = random_numbers[i + 1];
            isPointInsideCircle(x, y, &count);
        }
    } else {
        for (i = begin; i < end; i++) {
            x = genrand_real1();
            y = genrand_real1();
            isPointInsideCircle(x, y, &count);
        }
    }

    return (double)count / nb_iterations * 4;
}

/**
 * \fn void isPointInsideCircle(double x, double y, unsigned int* count)
 * \brief Methode qui indique si un point est inscrit dans un cercle de
 * diametre 1. On incremente un compteur si c'est le cas \param x Coordonnee du
 * point x \param y Coordonnee du point y \param count Compteur sur le nombre de
 * points totaux inscrit dans le cercle. C'est un pointeur car on le modifie a
 * l'interieur de la methode
 */
void isPointInsideCircle(double x, double y, unsigned long long int* count) {
    double z = x * x + y * y;
    if (z <= 1) {
        (*count)++;
    }
}
