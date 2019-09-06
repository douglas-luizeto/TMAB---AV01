#pragma once

#include <string>
#include <vector>

#include "TAluno.h"
#include "OrderAddress.h"

void criar_lista_ordem(std::vector<TAluno>* tabela, std::string ordem, std::vector<OrderAddress>* lista_ordem);

void print_lista_ordem(std::vector<OrderAddress> lista_ordem);

bool compara_str(std::string s1, std::string s2);

bool compara_int(std::string s1, std::string s2);

bool compara(std::string ordem,std::string s1, std::string s2);
