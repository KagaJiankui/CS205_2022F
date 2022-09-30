#pragma once
#include <cassert>
#include <complex>
// #include <cstddef>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "debug_print.h"

using std::vector;
void parseToString(const std::string& inputString, vector<std::complex<double>>& integerPart, vector<std::complex<double>>& decimalPart,
                   vector<std::complex<double>>& exponentialPart, int* type);
void StrToComplex(std::string& inputString, vector<std::complex<double>>& outputComplexVector);