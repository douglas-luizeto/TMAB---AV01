#pragma once

#include <string>
#include <vector>

#include "ordenar.h"

void merge(std::string ordem, std::vector<order_address>* lista, int l, int m, int r);

void mergesort(std::string ordem, std::vector<order_address>* lista, int l, int r); 