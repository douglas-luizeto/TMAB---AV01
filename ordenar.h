#pragma once

#include <string>
#include <vector>

#include "carregar_registro.h"

struct order_address
{
    std::string param_ordem;
    TAluno* end_aluno;
};

void criar_lista_ordem(std::vector<TAluno>* tabela, std::string ordem, std::vector<order_address>* lista_ordem);

void print_lista_ordem(std::vector<order_address> lista_ordem);

bool compara_str(std::string s1, std::string s2);

bool compara_int(std::string s1, std::string s2);

bool compara(std::string ordem,std::string s1, std::string s2);
