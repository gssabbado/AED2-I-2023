#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


#define MAX 100000

void swap (int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

void Selection (int n, int v[]) {
	int i, j, min;
	
	for (i = 0;  i < n - 1; i++) {             
		min = i;                               
		for (j = i + 1; j < n; j++) {           
			if (v[j] < v[min]) 
				min = j;
		}
		swap(&v[i], &v[min]);	
	}

}

int main () {
	FILE *p;
	int vetor[MAX]; // vetor de inteiros
	int i, n = MAX, j = MAX;
	int cont = 1;
	double time_spent = 0.0;
	
	p = fopen("Tamanho = 100000, Numeros quase ordenados.txt", "r");
	
	if (p == NULL)
		return -1;
		
	clock_t begin = clock();
	
	srand(time(NULL));
	
	
	for (i = 0; i < MAX; i++) {                   
		fscanf(p, "%d", &vetor[i]);				  //lê o arquivo e coloca o conteúdo nele dentro do vetor de inteiro
		//vetor[i] = (rand() % MAX);			  	  //inicializar vetor com numeros aleatorios
		//fprintf(p, "%d ", vetor[i]);			  	  //imprime os valores do vetor no arquivo
	}
		
	
	for (i = 0; i < MAX; i++) {                   //inicializar vetor com numeros quase ordenados
		fscanf(p, "%d", &vetor[i]);
/*		if(cont == 20) {
			vetor[i] = (rand() % MAX);
			cont = 0;
		}
		else vetor[i] = i;
		cont++;
		fprintf(p, "%d ", vetor[i]);
*/
	}
	
	
/*	for (i = 0; i < MAX; i++) {                   
		fscanf(p, "%d", &vetor[i]);					//lê o arquivo e coloca o conteúdo nele dentro do vetor de inteiro
		//vetor[i] = j--;							//inicializar vetor com numeros em ordem não ascendente
		//fprintf(p, "%d ", vetor[i]);				//imprime os valores do vetor no arquivo 
	}
*/	
//	for (i = 0; i < MAX; i++)	
//		printf("%d ", vetor[i]);	
	

	Selection(n, vetor); // Selection Sort para numeros inteiros
	
//	for (i = 0; i < MAX; i++)	
//		printf("%d ", vetor[i]);	
		
	clock_t end = clock();
	
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	
	printf("\n%lf", time_spent);

	fclose(p);
	
	return 0;
}
