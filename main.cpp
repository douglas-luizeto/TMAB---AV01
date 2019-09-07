/*===================================================================================

Tópicos em Matemática Aplicada B - AV01
Prof: Milton R. Ramirez 

Programadores: 
    
    Bianca Oliveira Bresciani de Carvalho
    DRE: 116169279
    
    Douglas Luizeto
    DRE: 112030355

===================================================================================*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

//estruturas de dados
#include "TAluno.h"
#include "OrderAddress.h"

#include "novo_aluno.h"
#include "carregar_registro.h"
#include "print_aluno.h"
#include "ordenar.h"
#include "mergesort.h"
#include "insertsort.h"
#include "comparar_algoritmos.h"

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
        cout << "3. Comparar algorítmos de ordenação (mergesort x quicksort)" << endl;
        cout << "4. Sair" << endl << endl;

        cout << "===============================================================" << endl << endl;

        cout << "Digite o número da opção desejada: ";
      
        getline(cin, line);
        stringstream linestream(line);
        linestream >> instruction;
     
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

            // limpar buffer cin
            getline(cin, line);

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

            // ordenar lista com mergesort
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
               print_aluno(lista_ordem[i], ordem, campos, i);
            } 
        }

        if(instruction == 3)
        {
            cout << "---Comparar algorítmos" << endl << endl;
            cout << "--------------------------------" << endl << endl;
            
            // comparar ordenações (desordenada)
            cout << "Tabela desordenada" << endl << endl;
            comparar_algoritmos("Nome", &tabela);
            cout << "--------------------------------" << endl << endl;

            // agora com tabela parcialmente ordenada
            ifstream infile2;
            infile2.open("./assets/registros_parc.txt");
            vector<TAluno> tabela2;
            carregar_registro(infile2, &tabela2);
            infile2.close();  

            cout << "Tabela parcialmente ordenada" << endl << endl;
            comparar_algoritmos("Nome", &tabela2);
            cout << "--------------------------------" << endl << endl;

            // com tabela totalmente ordenada
            tabela2.clear();
            infile2.open("./assets/registros_ord.txt");
            carregar_registro(infile2, &tabela2);
            infile2.close();

            cout << "Tabela totalmente ordenada" << endl << endl;
            comparar_algoritmos("Nome", &tabela2);
            cout << "--------------------------------" << endl << endl;
        }

        if(instruction == 4) break;

    }

    cout << "Sessão encerrada." << endl;

    return 0;

}