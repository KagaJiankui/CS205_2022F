//---------------------------------------------------------------------------

#include "JRegex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*---------------------------------------------------------------------------*/
void RegexTest(void)
{
  char* string;
  char* old_string;
  char* find_regex_expr;      // 查找用的正则表达式
  char* replace_regex_expr;   // 替换用的正则表达式
  char* find_string;          // 查找到的子串
  int   start;                // 查找到的子串的起始位置
  int   length;               // 子串的长度

  string = malloc(256);
  strcpy(string, "rat rot rpt");
  find_regex_expr = "r[aou]t";   // 意思是三个字符r?t, 第二个字符只能是a,o,u之一

  printf("\nRegexFind Example: string=%s, regex=%s\n", string, find_regex_expr);

  // Regex查找示例
  while (1 == RegexFind(string, find_regex_expr, &start, &length)) {
    // 找到后，从string截取出子串
    find_string = ExtractString(string, start, length);
    if (find_string != NULL) {
      printf("Found %s\n", find_string);
      free(find_string);        // 由于ExtractString时申请了内存，此处释放子串内存
    }
    string = string + length;   // 将指针指向下一个位置，以便继续查找
  }

}
/*---------------------------------------------------------------------------*/

int main(int argc, char* argv[])
{
  RegexTest();
  return 0;
}
//---------------------------------------------------------------------------
