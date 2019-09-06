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

bool compara_str(string s1, string s2) 
{
	int i = 0;

 	while(tolower(s1[i]) == tolower(s2[i])) i++;

	return tolower(s1[i]) <= tolower(s2[i]); 
}

bool compara_int(string s1, string s2)
{
	int n1 = stoul(s1);
	int n2 = stoul(s2);

	return n1 <= n2;
}

bool compara(string ordem, string s1, string s2)
{
    if(ordem == "Nome")
    {
        return compara_str(s1, s2);
    }
    if(ordem == "DRE")
    {
        return compara_int(s1,s2);
    }
}
