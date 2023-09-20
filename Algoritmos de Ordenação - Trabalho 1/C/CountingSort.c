#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX 100000

void CountingSort (int v[], int n) {
	int output[MAX], count[MAX]; 
	int i;
	int max = v[0];
	
	for (i = 1; i < MAX; i++) {
		if (v[i] > max)
			max = v[i];
	}
	
	for (i = 0; i <= MAX; i++) {
		count[i] = 0;
	}
	
	for (i = 0; i < MAX; i++) {
		count[v[i]]++;
	}
	
	for (i = 1; i <= MAX; i++) {
		count[i] += count[i - 1];
	}

	for (i = n - 1; i >= 0; i--) {
		output[count[v[i]] - 1] = v[i];
		count[v[i]]--;
	}
	
	for (i = 0; i < n; i++) {
		v[i] = output[i];
	}	
}

void printV (int v[], int tam) {
	int i;
	for (i = 0; i < tam; ++i)
		printf("%d ", v[i]);
	printf("\n");
}

int main () {
	FILE *p;
	int v[MAX];
	int n = MAX; 
	int i;
	double time_spent = 0.0;
	
	clock_t begin = clock();
	
	p = fopen("Tamanho = 100000, Numeros quase ordenados.txt", "r");

	srand(time(NULL));	
	
	for (i = 0; i < MAX; i++)                 
		fscanf(p, "%d", &v[i]);			 //lê o arquivo e coloca o conteúdo nele dentro do vetor de inteiro

	
	CountingSort(v, n);
	//printV(v, n);
	
	clock_t end = clock();
	
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	
	printf("\n%lf", time_spent);

	fclose(p);

	return 0;
}
