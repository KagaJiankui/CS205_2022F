#include <cassert>
#include <complex>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "debug_print.h"
using std::vector;
/**
 * @brief Parse a input string to three parts of an floating point number in scientific expression. Arbitrary precision.
 *
 * @param inputString
 * @param integerPart
 * @param decimalPart
 * @param indexPart
 * @param type
 */
void parseToString(const std::string& inputString, vector<std::complex<double>>& integerPart, vector<std::complex<double>>& decimalPart,
                   vector<std::complex<double>>& exponentialPart, int* type)
{
  std::string integerRegExp       = "([+-]?\\d+)";
  std::string floatingPointRegExp = integerRegExp + "\\.(\\d+)";
  std::string ieee754indexRegExp  = integerRegExp + "|(" + floatingPointRegExp + ")[Ee]" + integerRegExp;
  std::string integerPartString, decimalPartString, exponentialPartString;
  std::smatch integerMatcher, decimalMatcher, exponentialMatcher;
  int         idxExpString = 5, idxIntString = 2, idxIntStringOf754 = 3, idxDecStringOf754 = 4;
  auto        ret_exp = std::regex_match(inputString, exponentialMatcher, std::regex(ieee754indexRegExp));
  auto        ret_fp  = std::regex_match(inputString, decimalMatcher, std::regex(floatingPointRegExp));
  auto        ret_int = std::regex_match(inputString, integerMatcher, std::regex(integerRegExp));
  if (ret_exp) {
    *type = 3;
    debug_print(exponentialMatcher);
    exponentialPartString = exponentialMatcher[5];
  }
}

void StrToComplex(std::string& inputString, vector<std::complex<double>>& outputComplexVector)
{
  assert(inputString.size() <= outputComplexVector.size());
  int tempDigit = 0;
  for (int i = 0; i < inputString.size(); i++) {
    tempDigit = (char)inputString[i] - '0';
    outputComplexVector[i].real((double)tempDigit);
    outputComplexVector[i].imag(0.0);
  }
}

int main(int argc, const char** argv)
{
  std::string                  s                        = "123.45e678";
  vector<std::complex<double>> integerPartComplexVector = {0, 0};
  vector<std::complex<double>> decimalPartComplexVector = {0, 0};
  vector<std::complex<double>> indexPartComplexVector   = {0, 0};
  int                          type                     = 0;
  parseToString(s, integerPartComplexVector, decimalPartComplexVector, indexPartComplexVector, &type);
  return 0;
}