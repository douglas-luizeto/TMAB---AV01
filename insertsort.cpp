/* Implementação adaptada de:

https://www.geeksforgeeks.org/merge-sort/

*/

#include "insertsort.h"

using namespace std; 
  
/* Function to sort an array using insertion sort*/
void insertsort(string ordem, vector<OrderAddress> *lista)  
{  
    int n = (*lista).size();

    int i, j;
    OrderAddress key;

    for (i = 1; i < n; i++) 
    {  
        key = (*lista)[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && compara(ordem, key.param_ordem, (*lista)[j].param_ordem)) 
        {  
            (*lista)[j + 1] = (*lista)[j];  
            j = j - 1;  
        }  
        (*lista)[j + 1] = key;  
    }  
}  
  
