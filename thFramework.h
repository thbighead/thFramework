#ifndef THFRAMEWORK_H
#define THFRAMEWORK_H

#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "timer.h"
#include <unistd.h>

int aleatorio (int range, int teste);
void *alocaVetor (size_t tam, size_t size);
void **alocaMatriz (size_t n, size_t m, size_t size);
void barreira (int m);
int calcNucleosProcess (void);
int calcTamNumeros (int *numeros, int qtdNumeros);
double calculaPi (int qtdParcelasPrecisao);
void comoUsar(char* progName, char* argumentos);
int defineQtdThreads (int n);
double getMaiorDouble (double n1, double n2);
float getMaiorFloat (float n1, float n2);
int getMaiorInteiro (int n1, int n2);
void imprimeVetorDouble (double *vetor, int tam);
void imprimeVetorFloat (float *vetor, int tam);
void imprimeVetorInteiro (int *vetor, int tam);
void iniVetorDouble (double *vetor, int tam, double valorInicial);
void iniVetorFloat (float *vetor, int tam, float valorInicial);
void iniVetorInteiro (int *vetor, int tam, int valorInicial);
void liberaMemo (void *ptr);
void printaMatrizDouble (double **matriz, int n, int m);
void printaMatrizFloat (float **matriz, int n, int m);
void printaMatrizInteiro (int **matriz, int n, int m);
void setMatrizDouble (double **matriz, int n, int m);
void setMatrizFloat (float **matriz, int n, int m);
void setMatrizInteiro (int **matriz, int n, int m);
void threadCreate (pthread_t *thread, const pthread_attr_t *attr,
	void *(*start_routine) (void*), void *arg);
void threadJoin (int qtdThreads, pthread_t *threads);

#endif