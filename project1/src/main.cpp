#include "main.h"
#include "debug_print.h"


/**
 * @brief Parse a input string to three parts of an floating point number in scientific expression. Arbitrary precision.
 *
 * @param inputString
 * @param integerPart
 * @param decimalPart
 * @param indexPart
 * @param type
 */

int main(int argc, const char** argv)
{
  int                          type = 0,lenOfComplexVector=5;
  std::string                  s = "123.45e678";
  vector<std::complex<double>> integerPartComplexVector(lenOfComplexVector);
  vector<std::complex<double>> decimalPartComplexVector(lenOfComplexVector);
  vector<std::complex<double>> indexPartComplexVector(lenOfComplexVector);
  parseToString(s, integerPartComplexVector, decimalPartComplexVector, indexPartComplexVector, &type);
  debug_print(integerPartComplexVector);
  debug_print(decimalPartComplexVector);
  debug_print(indexPartComplexVector);
  return 0;
}

void parseToString(const std::string& inputString, vector<std::complex<double>>& integerPart, vector<std::complex<double>>& decimalPart,
                   vector<std::complex<double>>& exponentialPart, int* type)
{
  std::string integerRegExp       = "([+-]?\\d+)";
  std::string floatingPointRegExp = integerRegExp + "\\.(\\d+)";
  std::string ieee754indexRegExp  = "("+integerRegExp + "|" + floatingPointRegExp + ")[Ee]" + integerRegExp;
  // std::string integerPartString, decimalPartString, exponentialPartString;
  std::vector<std::string> matchedResult;
  std::smatch integerMatcher, decimalMatcher, exponentialMatcher;
  const int   idxExpString = 5, idxIntString = 2, idxIntStringOf754 = 3, idxDecStringOf754 = 4;
  auto        ret_exp = std::regex_match(inputString, exponentialMatcher, std::regex(ieee754indexRegExp));
  auto        ret_fp  = std::regex_match(inputString, decimalMatcher, std::regex(floatingPointRegExp));
  auto        ret_int = std::regex_match(inputString, integerMatcher, std::regex(integerRegExp));
  if (ret_exp) {
    *type = 3;
    for (auto pos = exponentialMatcher.begin(); pos != exponentialMatcher.end(); ++pos) {
      matchedResult.push_back(*pos);
    }
    StrToComplex(matchedResult[idxExpString], exponentialPart);
    if (!matchedResult[idxDecStringOf754].empty()) {
      StrToComplex(matchedResult[idxIntStringOf754], integerPart);
      StrToComplex(matchedResult[idxDecStringOf754], decimalPart);
    }
    else if (!matchedResult[idxIntString].empty()) {
      StrToComplex(matchedResult[idxIntString], integerPart);
    }
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