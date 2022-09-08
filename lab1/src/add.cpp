#include "add.h"
/**
 * @brief Simple add function receives and returns `INT` variables. Overflow vulnerable.
 *
 * @param number1
 * @param number2
 * @return int
 */
int add(int number1, int number2) { return number1 + number2; }
/**
 * @brief Simple add function to patch the overflowing problem when two `INT` variables add together.
 *
 * @param `long` number1
 * @param `long` number2
 * @return long
 */
long add_long(long number1, long number2) { return number1 + number2; }