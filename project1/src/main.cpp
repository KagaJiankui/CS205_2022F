#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

#include "parser.h"

void printArray(int* arr, int len);
int main(int argc, const char** argv) {
  std::string s1 = argv[1];
  std::string s2 = argv[2];
  const char* l1 = s1.c_str();
  const char* l2 = s2.c_str();
  int* ex1 = (int*)malloc((s1.length()) * sizeof(int));
  int* ex2 = (int*)malloc((s2.length()) * sizeof(int));
  two_word_parser((char*)l1, ex1);
  two_word_parser((char*)l2, ex2);
  printArray(ex1, s1.length());
  std::cout << std::endl;
  printArray(ex2, s2.length());
  std::cout << std::endl;
  return 0;
}

void printArray(int* arr, int len) {
  for (int i = 0; i < len; i++) {
    std::cout << *(arr + i);
  }
}