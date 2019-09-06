#pragma once

#include <string>
#include <vector>

#include "OrderAddress.h"
#include "ordenar.h"

void merge(std::string ordem, std::vector<OrderAddress>* lista, int l, int m, int r);

void mergesort(std::string ordem, std::vector<OrderAddress>* lista, int l, int r); 