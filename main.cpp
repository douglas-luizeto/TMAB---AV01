#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "novo_aluno.h"
#include "carregar_registro.h"
#include "ordenar.h"
#include "print_aluno.h"
#include "mergesort.h"

using namespace std;

int main()
{   
    int instruction; // opção do menu inicial
    string line; // raw input do usuário
    string temp; // auxilia na hora de extrair campos de 'line'

    while(true)
    {
        // carrega versão mais recente dos registros a cada iteração
        ifstream infile;
        infile.open("registros.txt");

        vector<TAluno> tabela;

        carregar_registro(infile, &tabela);

        infile.close();

        // menu inicial
        cout << "===============================================================" << endl << endl;
       
        cout << "Bem vindo ao FakeSiga! Escolha uma das opções abaixo." << endl << endl;

        cout << "1. Cadastrar novo aluno." << endl;
        cout << "2. Listar alunos" << endl;
        cout << "3. Sair" << endl << endl;

        cout << "===============================================================" << endl << endl;

        cout << "Digite o número da opção desejada: ";
        
        getline(cin, line);
        stringstream inst_linestream(line);
        inst_linestream >> instruction;

        cout << endl;

        if(instruction == 1)
        {
            cout << "---Cadastrar novo aluno" << endl << endl;

            // abrir arquivo registros.txt no modo 'append'
            ofstream outfile;
            outfile.open("registros.txt", ios_base::app);

            // chamar sub-rotina de cadastro de alunos
            cadastro(outfile);
            
            // fechar aquivo
            outfile.close();
        };

        if(instruction == 2)
        {
            string ordem;
            string campos;

            cout << "---Listar alunos" << endl << endl;

            cout << "Opções para ordenação: " << endl;
            cout << "\t* Nome (default)" << endl << "\t* DRE" << endl << endl;
            cout << "Campo para ordenação: " ;
            
            getline(cin, line);
            stringstream ordem_linestream(line);
            ordem_linestream >> ordem;
            
            // default = Nome
            if(ordem != "Nome" && ordem != "DRE") ordem = "Nome";

            cout << endl;

            // criar lista com parâmetro de ordenação e endereços da tabela
            vector<OrderAddress> lista_ordem;
            criar_lista_ordem(&tabela, ordem, &lista_ordem);

            // ordenar lista
            mergesort(ordem, &lista_ordem, 0, lista_ordem.size()-1);


            cout << "Opções de campos (campo de ordenação incluído automaticamente): " << endl;
            cout << "\t* Nome" << endl;
            cout << "\t* DRE" << endl;
            cout << "\t* CPF" << endl;
            cout << "\t* Curso" << endl;
            cout << "\t* Periodo" << endl;
            cout << "\t* Emails" << endl;
            cout << "\t* Tels" << endl;
            cout << "Campos para exibição: "; 

            getline(cin, line);
            stringstream campos_linestream(line);     
            while(campos_linestream >> temp) campos += " " + temp;                        
            
            cout << endl;
          
            cout << "Total de aluno cadastrados: " << tabela.size() << endl << endl;
            
            for(int i=0; i < lista_ordem.size(); i++)
            {   
                print_aluno(lista_ordem[i], ordem, campos);
            } 
  
        }

        if(instruction == 3) break;

    }

    cout << "Sessão encerrada." << endl;

    return 0;

}