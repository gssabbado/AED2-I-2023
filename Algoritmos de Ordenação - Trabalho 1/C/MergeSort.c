#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX 100000

void Intercalate (int p, int q, int r, int v[]) {
	int i, j , k, *w;
	w = (int*) malloc ((r-p) * sizeof (int));
	i = p;
	j = q;
	k = 0;
	
	while (i < q && j < r) {
		if (v[i] <= v[j])
			w[k++] = v[i++];
		else 
			w[k++] = v[j++];
	}
	while (i < q) w[k++] = v[i++];
	while (j < r) w[k++] = v[j++];
	for (i = p; i < r; i++)
		v[i] = w[i-p];
	free (w);
}

void Mergesort (int p, int r, int v[]) {
	int q;
	
	if (p < r - 1) {
		q = (p + r)/2;
		Mergesort (p, q, v);
		Mergesort (q, r, v);
		Intercalate (p, q, r, v);	
	}
}


int main () {
	FILE *p;
	int vetor[MAX];
	int i, n = MAX, j = MAX;
	double time_spent = 0.0;
	
	p = fopen("Tamanho = 100000, Numeros aleatorios.txt", "r");

	clock_t begin = clock();
	
	srand(time(NULL));


	for (i = 0; i < MAX; i++)                 
		fscanf(p, "%d", &vetor[i]);			 //lê o arquivo e coloca o conteúdo nele dentro do vetor de inteiro


	Mergesort(0, n, vetor);
	
	//printf("\n");
	//for (i = 0; i < MAX; i++)
	//	printf("%d ", vetor[i]);	

	clock_t end = clock();
	
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	
	printf("\n%lf", time_spent);

	fclose(p);
	
	return 0;	
}
