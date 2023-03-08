#ifndef MAIN_H
#define MAIN_H

#include "JRegex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Find the integer, decimal and exponent in a number in scientific expression.
 The output is an array [start 1,length 1,start 2,length 2,...,start n,length n],
 where the *start* indicates the beginning index of the substring and the *length* indicates the length of the substring.
 *
 * @param regex
 * @param target_string
 * @param positions
 */
void RegexTest(const char* regex, const char* target_string, int* positions);

#endif   // MAIN_H