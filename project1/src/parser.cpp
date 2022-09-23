#include "parser.h"

/**
 * @brief Parse the numerical type of input string.
 *
 * @param str
 * @param examine
 * @return int [0,1,2,3,4,5,6,-1]
 */
void two_word_parser(char* str, int* examine) {
  char* w0 = str;
  char* w1;
  int* result = examine;
  int flag_dot = 0, flag_exp = 0, len = strlen(str);
  for (int i = 0; i < len - 1; i++) {
    w1 = w0 + 1;
    if (flag_NaN(*w0)) {
      *(result) = -1;
    } else if (isdigit(*w0)) {
      if (isdigit(*w1)) {
        *(result) = 0;
      } else if (*w1 == '.') {
        *(result) = 1;
      } else if (flag_Ee(*w1)) {
        *(result) = 2;
      } else {
        *(result) = -1;
      }
    } else if (flag_pm(*w0)) {
      if (isdigit(*w1)) {
        *(result) = 3;
      } else {
        *(result) = -1;
      }
    } else if (*w0 == '.') {
      if (isdigit(*w1)) {
        *(result) = 4;
      } else {
        *(result) = -1;
      }
    } else if (flag_Ee(*w0)) {
      if (isdigit(*w1)) {
        *(result) = 5;
      } else if (flag_pm(*w1)) {
        *(result) = 6;
      } else {
        *(result) = -1;
      }
    }
    w0++;
    result++;
  }
}

inline int flag_NaN(char c) {
  return (!isdigit(c)) && (c != '+') && (c != '-') && (c != '.') &&
      (c != 'E') && (c != 'e');
}
inline int flag_Ee(char c) { return (c == 'E') || (c == 'e'); }

inline int flag_pm(char c) { return (c == '+') || (c == '-'); }