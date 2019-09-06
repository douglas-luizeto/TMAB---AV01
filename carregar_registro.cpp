#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "carregar_registro.h"

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

// passar campos a serem exibidos como argumentos
void print_aluno(TAluno aluno, string ordem, string campos)
{
    cout << "=============================" << endl << endl;

    if(campos.find("Nome") != string::npos || ordem == "Nome") 
        cout << "Nome: " << aluno.nome << endl;

    if(campos.find("DRE") != string::npos || ordem == "DRE") 
        cout << "DRE: " << aluno.DRE << endl;
    
    if(campos.find("CPF") != string::npos) cout << "CPF: " << aluno.CPF << endl;
    
    if(campos.find("Curso") != string::npos) cout << "Curso: " << aluno.curso << endl;
   
    if(campos.find("Periodo") != string::npos) cout << "Periodo: " << aluno.periodo << endl;

    if(campos.find("Emails") != string::npos)
    {
        cout << "E-mails: " << endl;
        for(int j=0; j < aluno.emails.size(); j++) cout << "\t* " + aluno.emails[j] << endl; 
    }

    if(campos.find("Tels") != string::npos)
    {
        cout << "Telefones: " << endl;
        for(int j=0; j < aluno.tels.size(); j++)
        {
            cout << "\t* "; 
            cout << aluno.tels[j] << endl;
        }
    }

    cout << endl;
}

void carregar_registro(ifstream& infile, vector<TAluno> *tabela)
{
    string aluno_str;

    while(infile >> aluno_str)
    {       
        (*tabela).push_back(string_to_TAluno(aluno_str));
    }
}
