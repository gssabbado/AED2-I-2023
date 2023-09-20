#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <fstream>

#define MAX 100000
using namespace std;


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

int main () {
	int v[MAX];
	int n = MAX; 
	int i;
	double time_spent = 0.0;
	ifstream File("Tamanho = 100000, Numeros aleatorios.txt");

	
	clock_t begin = clock();
	
	for (i = 0; i < MAX; i++) {
		File >> v[i];   			// Coloca os dados (números inteiros) dentro do vetor de tamanho MAX
	}

	CountingSort(v, n);

	
	clock_t end = clock();
	
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	
	printf("\n%lf", time_spent);


	return 0;
}
