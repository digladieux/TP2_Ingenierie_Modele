/**
 * \file main_test.cpp
 * \brief Fichier des tests unitaires
 * \author GLADIEUX CUNHA Dimitri
 * \date 18 octobre 2019
 */

#include "../header/generator.h"
#include "../header/monte_carlo.h"
#include "../header/mt19937ar.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern double random_numbers[];
extern const double mt_output_1000[];
extern long int MAX_ITERATION;

int Question1();
void Question2();
void Question3();
void Question4();
void Question5();
void Question6();

int main() {
    if(Question1()) {
        return EXIT_FAILURE ;
    }
    Question2();
    Question3();
    Question4();
    Question5();
    Question6();

    return EXIT_SUCCESS ;
}

int Question1() {

    // initialisationSeed();
    // int i = 0 ;
    // for (i ; i < 1000 ; i++) {
    //     if (mt_output_1000[i] != genrand_real2()) {
    //         printf("The experience is not reproductible") ;
    //         return EXIT_FAILURE;
    //     }

    // }
    
    return EXIT_SUCCESS;
}

void Question2() {

    int i = 0 ;
    MAX_ITERATION = 1000 ;
    for (i; i < MAX_ITERATION ; i++) {
        random_numbers[i] = genrand_real2() ;
    }
}

void Question3() {

    time_t begin, end;
    double function_time;
    begin = time(NULL);

    experiencesMonteCarlo(10, 1000000, 'n');

    end = time(NULL);
    function_time = difftime(end, begin);

    printf("The time to generate the number and to do monte carlo is %f\n",
           function_time);
}

void Question4() {

    time_t begin, end;
    double function_time;
    begin = time(NULL);

    MAX_ITERATION = 20000000 ;
    int i = 0 ;
    for (i; i < MAX_ITERATION ; i++) {
        random_numbers[i] = genrand_real2() ;
    }
    experiencesMonteCarlo(10, 1000000, 'y');

    end = time(NULL);
    function_time = difftime(end, begin);

    printf("The time to generate the number and to do monte carlo is %f\n",
           function_time);
}

void Question5() {

    time_t begin, end;
    double function_time;

    begin = time(NULL);
    genrand_real2();
    end = time(NULL);

    function_time = difftime(end, begin);

    printf("The time to generate 20 000 000 numbers  %f\n", function_time);

    begin = time(NULL);

    int i = 0;
    for (i; i < 20000000; i++) {
        random_numbers[i] = genrand_real2();
    }
    end = time(NULL);

    function_time = difftime(end, begin);

    printf("The time to see 20 000 000 numbers  %f\n", function_time);
}

void Question6() {

    int i = 0 ;
    MAX_ITERATION = 20000000000 ;
    for (i; i < 20000000; i++) {
        random_numbers[i] = genrand_real2() ;
    }

    time_t begin, end;
    double function_time;
    begin = time(NULL);

    
    unsigned long int numbers = 1000000000;
    experiencesMonteCarlo(10, numbers, 'n');

    end = time(NULL);
    function_time = difftime(end, begin);

    printf("The time to generate the number and to do monte carlo is %f\n",
           function_time);
}