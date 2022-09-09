# Lab1

## Exercise 1

### Code

```cpp
#include <iomanip>
#include <iostream>
int main() {
  std::cout.setf(std::ios::fixed);
  std::cout.precision(2);
  float a = 0.1, b = 0.2, c = 0.3;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
}
```

### Result

![cpp_cout](vscode-remote://wsl%2Bubuntu-22.04/home/lexington/CS205_2022F/lab1/figures/Snipaste_2022-09-09_17-13-08.png)

## Exercise 2

### Code

For the file `main.cpp`, the fatal bug is marked in the file.

```cpp
#include <iostream>

#include "add.h"
int main() {
  int num1 = 2147483647;
  int num2 = 1;
  /**
  *************BUG REVIEW************
  The maximum of the INT variable on 64-bit systems is $2^31-1=2147483647$.
  Thus the variable ``num1`` reaches the upper bond of the INT variable,
  adding this variable with any other nonzero variables leads to overflow.
  */

  long result = 0;
  result = add_long((long)num1, (long)num2);
  std::cout << "The result is " << result << std::endl;
  return 0;
}
```

The variable `num1` is approaching the upper limit of the `int` type, thus the add operation results in overflow.

For the file `add.cpp`, the variables are casted to `long` type to avoid overflow.

```cpp
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
```

The file `add.h` is modified to meet the modified `add.cpp`.

```cpp
#pragma once
int add(int n1, int n2);
long add_long(long number1, long number2);
```

### Result

![cpp_add](vscode-remote://wsl%2Bubuntu-22.04/home/lexington/CS205_2022F/lab1/figures/Snipaste_2022-09-09_17-19-30.png)