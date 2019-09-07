#include <iostream>

#include "print_aluno.h"

using namespace std;

void print_aluno(OrderAddress aluno, string ordem, string campos, int index)
{
    cout << "-----------------------------" << endl;

    cout << index + 1 << '.' << endl << endl;

    if(campos.find("Nome") != string::npos || ordem == "Nome") 
        cout << "Nome: " << (*aluno.end_aluno).nome << endl;

    if(campos.find("DRE") != string::npos || ordem == "DRE") 
        cout << "DRE: " << (*aluno.end_aluno).DRE << endl;
    
    if(campos.find("CPF") != string::npos) 
        cout << "CPF: " << (*aluno.end_aluno).CPF << endl;
    
    if(campos.find("Curso") != string::npos)
        cout << "Curso: " << (*aluno.end_aluno).curso << endl;
   
    if(campos.find("Periodo") != string::npos)
        cout << "Periodo: " << (*aluno.end_aluno).periodo << endl;

    if(campos.find("Emails") != string::npos)
    {
        cout << "E-mails: " << endl;
        for(int j=0; j < (*aluno.end_aluno).emails.size(); j++)
            cout << "\t* " + (*aluno.end_aluno).emails[j] << endl; 
    }

    if(campos.find("Tels") != string::npos)
    {
        cout << "Telefones: " << endl;
        for(int j=0; j < (*aluno.end_aluno).tels.size(); j++)
        {
            cout << "\t* "; 
            cout << (*aluno.end_aluno).tels[j] << endl;
        }
    }

    cout << endl;
}