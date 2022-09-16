#include <cstdio>
#include <cstring>

int main(int argc, const char** argv) {
  const char* str1 = argv[1];
  int len = strlen(str1), d = 0;
  printf("ASCII string: %s\n", str1);
  printf("Integer form: ");
  for (int i = 0; i < len; i++) {
    d = (int)(*(str1 + i));
    printf("%d ", d);
  }
  printf("\n");
  return 0;
}