#pragma once

#include <string>

#include "TAluno.h"

// estrutura para a lista que vai ser usada na ordenação

struct OrderAddress
{
    std::string param_ordem;
    TAluno* end_aluno;
};