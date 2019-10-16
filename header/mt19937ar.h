/**
 * \file mt19937ar.h
 * \brief Fichier d'entete du fichier mt19937ar.c
 * \author GLADIEUX CUNHA Dimitri
 * \date 18 octobre 2018
 */

#ifndef MT19937AR_H
#define MT19937AR_H
/**
 * \def _N_
 * \brief Period parameters
 */
#define _N_ 624

/**
  * \def M
  * \brief Period parameters
 */
#define M 397

/**
  * \def MATRIX_A
  * \brief constant vector a
 */
#define MATRIX_A 0x9908b0dfUL

/**
 * \def UPPER_MASK
 * \brief most significant w-r bits
 */
#define UPPER_MASK 0x80000000UL

/**
 * \def LOWER_MASK
 * \brief least significant r bits
 */
#define LOWER_MASK 0x7fffffffUL

void init_genrand(unsigned long s);
void init_by_array(unsigned long init_key[], int key_length);
unsigned long genrand_int32(void);
long genrand_int31(void);
double genrand_real1(void);
double genrand_real2(void);
double genrand_real3(void);
double genrand_res53(void);
void initialisationSeed() ;

#endif