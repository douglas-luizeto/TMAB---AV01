#include "ordenar.h"

using namespace std;

void criar_lista_ordem(vector<TAluno>* tabela, string ordem, vector<order_address>* lista_ordem)
{
    order_address temp; 
    
    for(int i = 0; i < (*tabela).size(); i++)
    {
        if(ordem == "Nome") temp.param_ordem = (*tabela)[i].nome;

        if(ordem == "DRE") temp.param_ordem = to_string((*tabela)[i].DRE);

        temp.end_aluno = &(*tabela)[i];
    
        (*lista_ordem).push_back(temp);
    }
}

// para fins de depuração
void print_lista_ordem(vector<order_address> lista_ordem)
{
    for(int i = 0; i < lista_ordem.size(); i++)
    {
        cout << lista_ordem[i].param_ordem << endl;
        cout << lista_ordem[i].end_aluno << endl;
    }
}