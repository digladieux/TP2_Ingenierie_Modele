/**
 * \file monte_carlo.h
 * \brief Fichier d'en tete de monte_carlo.c
 * \author GLADIEUX CUNHA Dimitri
 * \date 17 Octobre 2019
 */

#ifndef MONTE_CARLO_H
#define MONTE_CARLO_H

void experiencesMonteCarlo(const int nb_experiences, const int nb_iterations, char use_random_number_already_generated) ;
double monteCarlo(const int begin, const int end, char use_random_number_already_generated) ;
int Question7() ;
void calcTime(char use_random_number_already_generated) ;
#endif