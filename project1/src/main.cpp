#include <complex>
#include <string>
#include <vector>
#include <regex>
void parseToString(std::string inputString,
                   std::vector<std::complex<double>> integerPart,
                   std::vector<std::complex<double>> decimalPart,
                   std::vector<std::complex<double>> indexPart, int *type) {
  std::string integerRegExp = "([+-]?\\d+)";
  std::string floatingPointRegExp = integerRegExp + "\\.(\\d+)";
  std::string ieee754indexRegExp = integerRegExp+"|("+floatingPointRegExp+")[Ee]"+integerRegExp;
                   }