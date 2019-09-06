#include "comparar_algoritmos.h"

using namespace std;

void comparar_algoritmos(std::string ordem, std::vector<TAluno>* tabela_end)
{
    clock_t start;
    double  total_merge, total_insert;

    //criando lista com campo de ordenação e endereços
    vector<OrderAddress> lista_ordem;
    criar_lista_ordem(tabela_end, ordem, &lista_ordem);

    //medindo o tempo do mergesort
    start = clock();
    mergesort(ordem, &lista_ordem, 0, lista_ordem.size()-1);
    total_merge = (clock() - start)/ (double) CLOCKS_PER_SEC;

    //resetando ordenação em lista_ordem
    lista_ordem.clear();
    criar_lista_ordem(tabela_end, ordem, &lista_ordem);

    //medindo o tempo do insertsort
    start = clock();
    insertsort(ordem, &lista_ordem);
    total_insert = (clock() - start)/ (double) CLOCKS_PER_SEC;

    cout << "Tamanho da lista: " << lista_ordem.size() << endl;
    cout << "Tempo mergesort: " << total_merge << " s" << endl;
    cout << "Tempo insertsort: " << total_insert << " s" << endl;
}