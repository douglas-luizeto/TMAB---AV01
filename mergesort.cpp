/* Implementação adaptada de:

https://www.geeksforgeeks.org/merge-sort/

*/

#include "mergesort.h"

using namespace std;

// mescla dois subarrays de lista. 
// primeiro subarray é lista[l..m] 
// segundo subarray é lista[m+1..r] 

void merge(string ordem, vector<OrderAddress>* lista, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1; 
	int n2 = r - m; 

	// copiar dados para arrays temporários 
	OrderAddress L[n1], R[n2]; 

	for (i = 0; i < n1; i++) 
		L[i] = (*lista)[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = (*lista)[m + 1+ j]; 

	// mescla arrays temporários 
	i = 0; // índice do primeiro subarray 
	j = 0; // índice do segundo subarray 
	k = l; // índice do subarray mesclado
	while (i < n1 && j < n2) 
	{ 
		if (compara(ordem, L[i].param_ordem, R[j].param_ordem)) 
		{ 
			(*lista)[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			(*lista)[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	// copia elementos restantes de L[], caso existam
	while (i < n1) 
	{ 
		(*lista)[k] = L[i]; 
		i++; 
		k++; 
	} 

	// copia elementos restantes de R[], caso existam
	while (j < n2) 
	{ 
		(*lista)[k] = R[j]; 
		j++; 
		k++; 
	} 

}

// l indica o índice inicial do subarray de lista que deve ser ordenada
// r indica o índica final
void mergesort(string ordem, vector<OrderAddress>* lista, int l, int r) 
{ 
	if (l < r) 
	{ 
		// mesmo que (l+r)/2, mais estável numericamente
		int m = l+(r-l)/2; 

		// ordena primeira e segunda metades
		mergesort(ordem, lista, l, m); 
		mergesort(ordem, lista, m+1, r); 

		merge(ordem, lista, l, m, r); 
	} 
} 



