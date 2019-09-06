#pragma once

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