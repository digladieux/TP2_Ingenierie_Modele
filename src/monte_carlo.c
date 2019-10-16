#include <math.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../header/monte_carlo.h"
#include "../header/mt19937ar.h"

extern const double random_numbers[];
void isPointInsideCircle(double x, double y, unsigned int* count);

void experiencesMonteCarlo(const unsigned int nb_experiences,
                           const unsigned int nb_iterations,
                           char use_random_number_already_generated) {
    unsigned int i;
    double average_gap = 0;
    for (i = 0; i < nb_experiences; i++) {
        double pi = monteCarlo(i * nb_iterations, (i + 1) * nb_iterations,
                               nb_iterations);
        double tmp = M_PI - pi;
        average_gap += tmp < 0 ? tmp * (-1) : tmp;
        printf("%u Step - Value of Pi : %f\n", i + 1, pi);
    }

    average_gap /= nb_experiences;
    printf("Average Gap : %f\n", average_gap);
}

double monteCarlo(const unsigned int begin, const unsigned int end,
                  char use_random_number_already_generated) {
    double x, y;
    unsigned int nb_iterations = end - begin, i = begin;
    unsigned int count = 0;

    if (use_random_number_already_generated != 'n') {
        for (i = begin; i < begin + nb_iterations * 2; i += 2) {
            x = random_numbers[i];
            y = random_numbers[i + 1];
            isPointInsideCircle(x, y,  &count);
        }
    } else {
        for (i = begin; i < end; i++) {
            x = genrand_real1();
            y = genrand_real1();
            isPointInsideCircle(x, y, &count);
        }
    }

    return (double)count / nb_iterations * 4 ;
}

void isPointInsideCircle(double x, double y, unsigned int* count) {
    double z = x * x + y * y;
    if (z <= 1) {
        (*count)++;
    }
}
