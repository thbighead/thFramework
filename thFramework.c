#include "thFramework.h"

#define DEZ 10

int aleatorio (int range, int teste)
{
	int x;
	if (teste)
	{
		while (range < 2)
		{
			printf("função random: o range %d passado é inválido, por favor digite um valor < 2 para range:\n", range);
			scanf("%d", &range);
		}
	}
	else if (range < 2)
	{
		range = DEZ;
	}

	while (x >= (RAND_MAX - (RAND_MAX % range)))
	{
		srand(time(NULL));
		x = rand();
	}
	x %= range;

	return x;
}

void *alocaVetor (size_t tam, size_t size)
{
	void *vetor;

	if (!(vetor = calloc(tam, size)))
	{
		printf("função alocaVetor: erro ao alocar memória do vetor com calloc\n");
		exit(-1);
	}

	return vetor;
}

void **alocaMatriz (size_t n, size_t m, size_t size)
{
	int i;
	void **matriz;

	if (!(matriz = calloc(n, sizeof(void*))))
	{
		printf("função alocaMatriz: erro ao alocar espaço das linhas na memória\n");
		exit(-1);
	}
	for (i = 0; i < n; ++i)
	{
		if (!(matriz[i] = calloc(m, size)))
		{
			printf("função alocaMatriz: erro ao alocar espaço da coluna %d na memória\n", i);
			exit(-1);
		}
	}

	return matriz;
}

void barreira (int qtdThreads)
{
	static int threadsCount = 0;
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static pthread_cond_t condition;

	pthread_mutex_lock(&lock);
	threadsCount++;

	if (threadsCount < qtdThreads)
	{
		// printf("Aguarde a largada...\n");
		pthread_cond_wait(&condition, &lock); // libera o lock (momentaneamente) e espera por um sinal para continuar
	}
	else
	{
		// printf("É dada a largada\n");
		threadsCount = 0;
		pthread_cond_broadcast(&condition); // libera todas as threads que estejam esperando um sinal para sair do wait
	}
	pthread_mutex_unlock(&lock);

	pthread_mutex_destroy(&lock);
	pthread_cond_destroy(&condition);
}

int calcNucleosProcess (void)
{
	return sysconf(_SC_NPROCESSORS_ONLN);
}

int calcTamNumeros (int *numeros, int qtdNumeros)
{
	int i, num, tam = 0;

	for (i = 0; i < qtdNumeros; ++i)
	{
		num = numeros[i];

		while (num)
		{
			tam++;
			num /= 10;
		}
	}

	return tam;
}

double calculaPi (int qtdParcelasPrecisao)
{
	int i;
	double pi = 0;

	if (qtdParcelasPrecisao < 0)
	{
		qtdParcelasPrecisao = DEZ;
	}

	for (i = 0; i < qtdParcelasPrecisao; ++i)
	{
		pi += pow(-1, i)/(2*i+1);
	}
	pi *= 4;

	return pi;
}

void comoUsar(char* progName, char* argumentos)
{
	fprintf(stderr, "como usar: ./%s %s\n", progName, argumentos);
	exit(0);
}

int defineQtdThreads (int n)
{
	if (n > 0)
	{
		return n;
	}
	else
	{
		return calcNucleosProcess();
	}
}

double getMaiorDouble (double n1, double n2)
{
	if (n1 > n2)
	{
		return n1;
	}
	else
	{
		return n2;
	}
}

float getMaiorFloat (float n1, float n2)
{
	if (n1 > n2)
	{
		return n1;
	}
	else
	{
		return n2;
	}
}

int getMaiorInteiro (int n1, int n2)
{
	if (n1 > n2)
	{
		return n1;
	}
	else
	{
		return n2;
	}
}

void imprimeVetorDouble (double *vetor, int tam)
{
	int i;

	for (i = 0; i < tam; ++i)
	{
		printf("%e\t", vetor[i]);
	}
	printf("\n");
}

void imprimeVetorFloat (float *vetor, int tam)
{
	int i;

	for (i = 0; i < tam; ++i)
	{
		printf("%f\t", vetor[i]);
	}
	printf("\n");
}

void imprimeVetorInteiro (int *vetor, int tam)
{
	int i;

	for (i = 0; i < tam; ++i)
	{
		printf("%d\t", vetor[i]);
	}
	printf("\n");
}

void iniVetorDouble (double *vetor, int tam, double valorInicial)
{
	int i;

	for (i = 0; i < tam; ++i)
	{
		vetor[i] = valorInicial;
	}
}

void iniVetorFloat (float *vetor, int tam, float valorInicial)
{
	int i;

	for (i = 0; i < tam; ++i)
	{
		vetor[i] = valorInicial;
	}
}

void iniVetorInteiro (int *vetor, int tam, int valorInicial)
{
	int i;

	for (i = 0; i < tam; ++i)
	{
		vetor[i] = valorInicial;
	}
}

void liberaMemo (void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void printaMatrizDouble (double **matriz, int n, int m)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; ++j)
		{
			printf("%e\t", matriz[i][j]);
		}
		printf("\n");
	}
}

void printaMatrizFloat (float **matriz, int n, int m)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; ++j)
		{
			printf("%f\t", matriz[i][j]);
		}
		printf("\n");
	}
}

void printaMatrizInteiro (int **matriz, int n, int m)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; ++j)
		{
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}
}

void setMatrizDouble (double **matriz, int n, int m)
{
	int i, j;

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			scanf("%lf", &matriz[i][j]);
		}
	}
}

void setMatrizFloat (float **matriz, int n, int m)
{
	int i, j;

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			scanf("%f", &matriz[i][j]);
		}
	}
}

void setMatrizInteiro (int **matriz, int n, int m)
{
	int i, j;

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			scanf("%d", &matriz[i][j]);
		}
	}
}

void threadCreate (pthread_t *thread, const pthread_attr_t *attr,
	void *(*start_routine) (void*), void *arg)
{
	int id;

	if ((id = pthread_create(thread, attr, *start_routine, arg)))
	{
		printf("--ERRO: pthread_create()\n");
		printf("error number %d\n", id);
		exit(-1);
	}
}

void threadJoin (int qtdThreads, pthread_t *threads)
{
	int i, erro;

	for (i = 0; i < qtdThreads; ++i)
	{
		// printf("thread%d\n", i);
		if ((erro = pthread_join(threads[i], NULL)))
		{
			printf("--ERRO: pthread_join()\n");
			printf("error number %d\n", erro);
			exit(-1);
		}
	}
}