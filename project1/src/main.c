#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
  const char* regex = "[^\\.e]+";
  char*       find_string;
  char*       tgt_str = "1.0e2";
  int*        idx     = (int*)malloc(16);
  RegexTest(regex, tgt_str, idx);
  for (int i = 0; i < 16; i++) {
    printf("%d ", idx[i]);
  }
  printf("\n");
  for (int j = 0; j < 16; j += 2) {
    find_string = ExtractString(tgt_str, idx[j], idx[j + 1]);
    if (find_string != NULL) {
      printf("%s ", find_string);
      free(find_string);
    }
  }
  return 0;
}

void RegexTest(const char* regex, const char* target_string, int* positions)
{
  int   start;
  int   length;
  int   index       = 0;
  int   init_length = 0;
  char* string      = malloc(256);
  strcpy(string, target_string);
  while (1 == RegexFind(string, regex, &start, &length)) {
    positions[index++] = init_length;
    positions[index++] = length;
    string             = string + length;
    init_length        = init_length + length;
  }
}
