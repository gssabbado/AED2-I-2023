#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <fstream>

#define MAX 100000
using namespace std;


void Intercalate (int p, int q, int r, int v[]) {
	int i, j, k, *aux;
	aux = (int*) malloc ((r - p) * sizeof (int));
	i = p;
	j = q;
	k = 0;
	
	while (i < q && j < r) {
		if (v[i] <= v[j])
			aux[k++] = v[i++];
		else
			aux[k++] = v[j++];
	}
	while (i < q) aux[k++] = v[i++];
	while (j < r) aux[k++] = v[j++];
	for (i = p; i < r; i++)
		v[i] = aux[i - p];
	free(aux);
}

void MergeSort (int p, int r, int v[]) {
	int q;
	
	if (p < r - 1) {
		q = (p + r)/2;
		MergeSort (p, q, v);
		MergeSort (q, r, v);
		Intercalate (p, q, r, v);
	}
}


int main () {
	int v[MAX];
	int i, n = MAX, j = MAX;	
	double time_spent = 0.0;
	ifstream File("Tamanho = 100000, Numeros quase ordenados.txt");
	
	clock_t begin = clock();

	
	for (i = 0; i < MAX; i++) {
		File >> v[i];			// Coloca os dados (números inteiros) dentro do vetor de tamanho MAX
	}
	
		
	MergeSort(0, n, v);
	
	
	clock_t end = clock();
	
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	
	cout << "\n " << fixed << time_spent << setprecision(5);
	
	
	return 0;
}
