#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "novo_aluno.h"
#include "carregar_registro.h"

using namespace std;

int main()
{   
    int instruction;

    while(true)
    {
        // carrega registros a cada iteração
        ifstream infile;
        infile.open("registros.txt");

        vector<TAluno> tabela;

        carregar_registro(infile, &tabela);

        infile.close();

        // menu inicial
        cout << "===============================================================" << endl << endl;
       
        cout << "Bem vindo ao FakeSiga! Escolha uma das opções abaixo." << endl << endl;

        cout << "1. Cadastrar novo aluno." << endl;
        cout << "2. Fazer Consulta" << endl;
        cout << "3. Listar alunos" << endl;
        cout << "4. Sair" << endl << endl;

        cout << "===============================================================" << endl << endl;

        cout << "Digite o número da opção desejada: ";
        cin >> instruction;
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
            cout << "---Fazer consulta" << endl << endl;
            // inserir campos para consulta
        };

        if(instruction == 3)
        {
            cout << "---Listar alunos" << endl << endl;

            cout << "Total de aluno cadastrados: " << tabela.size() << endl << endl;
            
            for(int i=0; i < tabela.size(); i++)
            {   
                print_aluno(tabela[i]);
            }              
        }

        if(instruction == 4) break;

    }

    cout << "Sessão encerrada." << endl;

    return 0;

}