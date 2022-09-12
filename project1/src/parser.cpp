#include "parser.h"
#include <cctype>

/**
 * @brief Parse the numerical type of input string. Possible returns:
 * 0 = `int`
 *
 * 1 = `long`
 *
 * 2 = `long long`
 *
 * 3 = `arbitary accuracy`
 *
 * 4 = `double`
 *
 * 5 = IEEE 754 `double`
 *
 * -1 = `error input`
 *
 * @param argv
 * @return int [0,1,2,3,4,5,-1]
 */
int parser(char *argv) {
  if ((!(std::isdigit(*argv)))||(*(argv)!='+')|(*(argv)!='-')) return -1;
}