#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct TAluno
{
    std::string nome;
    unsigned long int DRE;
    unsigned long int CPF;
    std::vector<std::string> emails; 
    std::vector<unsigned long int> tels;
    std::string curso;
    unsigned int periodo;
};

TAluno string_to_TAluno(std::string aluno_str);

void carregar_registro(std::ifstream& infile, std::vector<TAluno>* tabela);

