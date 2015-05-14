#include "thFramework.h"

int main(int argc, char const *argv[])
{
	return 0;
}



/* TESTE DE ALOCA VETOR = PERFEITO */
// int main(int argc, char const *argv[])
// {
// 	int i, j;
// 	float **matriz;

// 	alocaVetor(matriz, 5, sizeof(float*));

// 	for (i = 0; i < 5; ++i)
// 	{
// 		alocaVetor(matriz[i], 5, sizeof(float));
// 	}

// 	for (i = 0; i < 5; ++i)
// 	{
// 		for (j = 0; j < 5; ++j)
// 		{
// 			matriz[i][j] = 5;
// 		}
// 	}

// 	printaMatrizFloat(matriz, 5, 5);
// 	liberaMemo(matriz);
// 	if (matriz)
// 	{
// 		printf("não consegui liberar a matriz da memória\n");
// 		printaMatrizFloat(matriz, 5, 5);
// 	}

// 	return 0;
// }



/* ALOCA MATRIZ FUNCIONANDO! */
// int main(int argc, char *argv[])
// {
// 	int i, j, n = 5, m = 3, **matriz;

// 	alocaMatriz(matriz, n, m, sizeof(int));

// 	for (i = 0; i < n; ++i)
// 	{
// 		for (j = 0; j < m; ++j)
// 		{
// 			printf("%d\t", matriz[i][j]);
// 		}
// 		printf("\n");
// 	}
// 	liberaMemo(matriz);

// 	return 0;
// }



/* TESTE PARA O TAMANHO EM BYTES DE PONTEIROS DE DIFERENTES TIPOS (É TUDO 4 BYTES VÉI!) */
// int main(int argc, char *argv[])
// {
// 	printf("sizeof(int*) = %d\n", sizeof(int*));
// 	printf("sizeof(char*) = %d\n", sizeof(char*));
// 	printf("sizeof(float*) = %d\n", sizeof(float*));
// 	printf("sizeof(double*) = %d\n", sizeof(double*));
// 	printf("sizeof(void*) = %d\n", sizeof(void*));
// 	return 0;
// }



/* TESTE DE FUNÇÕES COM A BIBLIOTECA PTHREADS */
// #include <pthread.h>

// #define C 5

// int s = 0;

// void *faz (void* arg);

// int main(int argc, char const *argv[])
// {
// 	int i, threadsArgs[C];
// 	pthread_t *threads;

// 	threads = alocaVetor(C, sizeof(pthread_t));

// 	for (i = 0; i < C; ++i)
// 	{
// 		threadsArgs[i] = i;
// 		threadCreate(&threads[i], NULL, faz, &threadsArgs[i]);
// 	}
// 	threadJoin(C, threads);

// 	free(threads);

// 	pthread_exit(NULL);
// }

// void *faz (void* arg)
// {
// 	int id = *((int*) arg);

// 	barreira(C);
// 	s++;
// 	printf("thread%d somou\n", id);

// 	pthread_exit(NULL);
// }