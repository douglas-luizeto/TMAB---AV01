#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "carregar_registro.h"
#include "ordenar.h"

using namespace std;

TAluno string_to_TAluno(string aluno_str)
{
    TAluno aluno;

    aluno.CPF = stoul(aluno_str.substr(0, 11)); //termina em 10

    aluno.DRE = stoul(aluno_str.substr(11,9));  // termina em 19

    int inicio_campo, final_campo = 19; 
    int separador;
  
    for(int i=0; i<3; i++)
    {
        inicio_campo = final_campo + 1;
        final_campo = aluno_str.find(',', inicio_campo);

        if(i == 0) aluno.nome = aluno_str.substr(inicio_campo, final_campo - inicio_campo);


        else if(i == 1) aluno.curso = aluno_str.substr(inicio_campo, final_campo - inicio_campo);

        else if(i == 2) aluno.periodo = stoi(aluno_str.substr(inicio_campo, final_campo - inicio_campo));
    } 


    separador = aluno_str.find('&');

    while(final_campo < separador-1)
    {
        inicio_campo = final_campo + 1;
        final_campo = aluno_str.find(',', inicio_campo);

        aluno.emails.push_back(aluno_str.substr(inicio_campo, final_campo - inicio_campo));
    }

    inicio_campo = final_campo + 2;
    
    while(inicio_campo < aluno_str.length())
    {   
        final_campo = aluno_str.find(',', inicio_campo);

        aluno.tels.push_back(stoul(aluno_str.substr(inicio_campo, final_campo - inicio_campo)));
        inicio_campo = final_campo + 1;
    }
    
    return aluno;
}

void carregar_registro(ifstream& infile, vector<TAluno>* tabela)
{
    string aluno_str;

    while(infile >> aluno_str)
    {   
        (*tabela).push_back(string_to_TAluno(aluno_str));
    }
}
