#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#define MAX 1000
using namespace std;

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
	int v[MAX];
	int i, n = MAX, j = MAX;	
	double time_spent = 0.0;
	ifstream File("Tamanho = 1000, Numeros aleatorias.txt");
	
	
	clock_t begin = clock();

	for (i = 0; i < MAX; i++) {
		File >> v[i];			 // Coloca os dados (números inteiros) dentro do vetor de tamanho MAX
		//cout << v[i] << " ";   // imprime cada valor do vetor na posição i
	}
		
	Selection(n, v);

		
/*	for (i = 0; i < MAX; i++) {  // imprime o vetor após ser ordenado
		cout << v[i] << " ";
	}
*/	
		
	clock_t end = clock();
	
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	
	cout << "\n " << fixed << time_spent << setprecision(5);
	
	File.close();
	
	return 0;
}

