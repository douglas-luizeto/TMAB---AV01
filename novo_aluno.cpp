#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "novo_aluno.h"

using namespace std;

// pega input do usuario para um unico aluno e grava no arquivo registro.txt
void entrada(ofstream& outfile)
{
    string registro_str;
    string temp;

    char resposta_email, resposta_tel;
    unsigned int email_index = 1, tel_index = 1;

    /* 
    registro é gravado na seguinte ordem:

    cpf dre nome , curso, periodo , emails(,) ,& tels(,),
    */
    
    cout << "Nome: ";
    cin >> temp;
    cout << endl;
    registro_str = temp;

    cout << "DRE: ";
    cin >> temp;
    cout << endl;
    registro_str = temp + registro_str;
     
    cout << "CPF: ";
    cin >> temp;
    cout << endl;
    registro_str = temp + registro_str;

    cout << "Curso: ";
    cin >> temp;
    cout << endl;
    registro_str += "," + temp;

    cout << "Periodo: ";
    cin >> temp;
    cout << endl;
    registro_str += "," + temp;

    do
    {   
        resposta_email = 'n'; //para evitar loops infinitos quando há erros nas entradas

        cout << "e-mail " << email_index << ": ";
        cin >> temp;
        cout << endl;
        registro_str += "," + temp;

        cout << "Voce tem " << email_index << " e-mails cadastrados." << endl;

        cout << "Inserir novo e-mail? (s/n) ";
        cin >> resposta_email;
        cout << endl;

        resposta_email = tolower(resposta_email);

        if(resposta_email == 's') email_index++; 

        if(email_index == 6)
        {
            cout << "Número máximo de emails foi atingido." << endl << endl;
            break;
        }
    
    } while(resposta_email == 's');

    registro_str += ",&";

    do
    {
        resposta_tel = 'n'; //para evitar loops infinitos quando há erros nas entradas

        cout << "Telefone " << tel_index << ": ";
        cin >> temp;
        cout << endl;
        registro_str += temp + ",";

        cout << "Voce tem " << tel_index << " telefones cadastrados." << endl;

        cout << "Inserir novo telefone? (s/n) ";
        cin >> resposta_tel;
        cout << endl;

        resposta_tel = tolower(resposta_tel);

        if(resposta_tel == 's') tel_index++;

        if(tel_index == 6)
        {
            cout << "Número máximo de telefones foi atingido." << endl << endl;
            break;
        }

    } while(resposta_tel == 's');

    // grava registro no arquivo registros.txt
    outfile << registro_str << endl;
};


void cadastro(ofstream& outfile)
{

    char resposta_aluno;

    do
    {
        //gambiarra para evitar loops infinitos quando há erros nas entradas
        resposta_aluno = 'n'; 

        entrada(outfile);

        cout << "Inserir novo aluno? (s/n) ";
        cin >> resposta_aluno;

        cout << endl;

        resposta_aluno = tolower(resposta_aluno);

    } while(resposta_aluno == 's');
  
    cout << "Cadastro concluído." << endl << endl;

};


