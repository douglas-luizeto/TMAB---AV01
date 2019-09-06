#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "TAluno.h"


TAluno string_to_TAluno(std::string aluno_str);

void carregar_registro(std::ifstream& infile, std::vector<TAluno>* tabela);

