/* Implementação adaptada de:

https://www.geeksforgeeks.org/merge-sort/

*/

#include "insertsort.h"

using namespace std; 
  
void insertsort(string ordem, vector<OrderAddress> *lista)  
{  
    int n = (*lista).size();

    int i, j;  // indices para manipular a lista
    OrderAddress pivot; // pivô

    for (i = 1; i < n; i++) 
    {  
        // primeiro pivô é o segundo elemento da lista
        pivot = (*lista)[i];  
        // que será comparado com o primeiro elemento
        j = i - 1;  
  
        /* 
        move os elementos de lista[0..i-1] maiores  
        que o pivo uma posição a frente da atual 
        */
        while (j >= 0 && compara(ordem, pivot.param_ordem, (*lista)[j].param_ordem)) 
        {  
            (*lista)[j + 1] = (*lista)[j];  
            j = j - 1;  
        }
        /* 
        quando encontramos um elemento menor 
        que o pivô, este assume a posição logo
        após este elemento
        */  
        (*lista)[j + 1] = pivot;  
    }  
}  
  
