#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define LONG_DIGIT 9
typedef struct
{
  int    integer;
  double double_number;
  char   flag_double;
} Number;

void ParseInput(Number* number_output, const char* input_str)
{
  char* integer_str       = (char*)malloc(LONG_DIGIT);
  int   flag_negative_int = 0;
  int   flag_double       = 0;
  if ((*input_str == '-')) {
    flag_negative_int = 1;
    input_str++;
  }
  else if (*input_str == '+') {
    flag_negative_int = 0;
    input_str++;
  }
  while (*input_str == '0') {
    input_str++;
  }
  int idx_int = 0;
  while (('0' <= *input_str) && (*input_str <= '9')) {
    if (idx_int > LONG_DIGIT) {
      break;
    }
    integer_str[idx_int] = (int)(*input_str);
    input_str++;
    idx_int++;
  }
  if (*input_str == '.') {
    number_output->flag_double = 1;
    idx_int++;
    integer_str[idx_int] = '.';
    input_str++;
    while (('0' <= *input_str) && (*input_str <= '9')) {
      if (idx_int > LONG_DIGIT * 4) {
        break;
      }
      integer_str[idx_int] = (int)(*input_str);
      input_str++;
      idx_int++;
    }
  }
  if (number_output->flag_double == 1) {
    number_output->double_number = atof(integer_str) * (flag_negative_int ? -1 : 1);
  }
  else {
    number_output->integer = atoi(integer_str) * (flag_negative_int ? -1 : 1);
  }
}

void numberAdd(Number* num1, Number* num2, Number* res)
{
  res->flag_double = num1->flag_double || num2->flag_double;
  if (res->flag_double) {
    if (num1->flag_double) {
      if (num2->flag_double) {
        res->double_number = num1->double_number + num2->double_number;
      }
      else {
        res->double_number = num1->double_number + num2->integer;
      }
    }
    else if (num2->flag_double) {
      if (num1->flag_double) {
        res->double_number = num1->double_number + num2->double_number;
      }
      else {
        res->double_number = num1->integer + num2->double_number;
      }
    }
  }
  else {
    res->integer = num1->integer + num2->integer;
  }
}

void numberMinus(Number* num1, Number* num2, Number* res)
{
  res->flag_double = num1->flag_double || num2->flag_double;
  if (res->flag_double) {
    if (num1->flag_double) {
      if (num2->flag_double) {
        res->double_number = num1->double_number - num2->double_number;
      }
      else {
        res->double_number = num1->double_number - num2->integer;
      }
    }
    else if (num2->flag_double) {
      if (num1->flag_double) {
        res->double_number = num1->double_number - num2->double_number;
      }
      else {
        res->double_number = num1->integer - num2->double_number;
      }
    }
  }
  else {
    res->integer = num1->integer - num2->integer;
  }
}

void numberMul(Number* num1, Number* num2, Number* res)
{
  res->flag_double = num1->flag_double || num2->flag_double;
  if (res->flag_double) {
    if (num1->flag_double) {
      if (num2->flag_double) {
        res->double_number = num1->double_number * num2->double_number;
      }
      else {
        res->double_number = num1->double_number * num2->integer;
      }
    }
    else if (num2->flag_double) {
      if (num1->flag_double) {
        res->double_number = num1->double_number * num2->double_number;
      }
      else {
        res->double_number = num1->integer * num2->double_number;
      }
    }
  }
  else {
    res->integer = num1->integer * num2->integer;
  }
}

void numberDiv(Number* num1, Number* num2, Number* res)
{
  res->flag_double = num1->flag_double || num2->flag_double;
  if (res->flag_double) {
    if (num1->flag_double) {
      if (num2->flag_double) {
        if (num2->double_number == 0) {
          printf("Divisor cannot be zero");
          exit(1);
        }
        res->double_number = num1->double_number / num2->double_number;
      }
      else {
        if (num2->integer == 0) {
          printf("Divisor cannot be zero");
          exit(1);
        }
        res->double_number = num1->double_number / num2->integer;
      }
    }
    else if (num2->flag_double) {
      if (num2->double_number == 0) {
        printf("Divisor cannot be zero");
        exit(1);
      }
      if (num1->flag_double) {
        res->double_number = num1->double_number / num2->double_number;
      }
      else {

        res->double_number = num1->integer / num2->double_number;
      }
    }
  }
  else {
    if (num2->integer == 0) {
      printf("Divisor cannot be zero");
      exit(1);
    }
    res->integer = num1->integer / num2->integer;
  }
}

int main(int argc, char** argv)
{
  if (argc != 4) {
    printf("2 oprands and 1 operators is required.");
    return 0;
  }
  char op1   = *argv[1];
  char op2   = *argv[3];
  char oprt1 = *argv[2];
  if (((op1 != '-') && (op1 != '+')) && ((op1 < '0') || (op1 > '9'))) {
    printf("Oprand 1 is not a valid number.");
    return 0;
  }
  if ((op2 != '-') && (op2 != '+') && ((op2 < '0') || (op2 > '9'))) {
    printf("Oprand 2 is not a valid number.");
    return 0;
  }
  if (!((oprt1 == '+') || (oprt1 == '-') || (oprt1 == '*') || (oprt1 == '/'))) {
    printf("Invalid operator.");
    return 0;
  }
  Number num1   = {0, 0, 0};
  Number num2   = {0, 0, 0};
  Number result = {0, 0, 0};
  ParseInput(&num1, argv[1]);
  ParseInput(&num2, argv[3]);
  switch (oprt1) {
  case '+': numberAdd(&num1, &num2, &result); break;
  case '-': numberMinus(&num1, &num2, &result); break;
  case '*': numberMul(&num1, &num2, &result); break;
  case '/': numberDiv(&num1, &num2, &result); break;
  default: printf("Invalid operator."); return 0;
  }
  if (result.flag_double == 0) {
    printf("%d %c %d = %d", num1.integer, oprt1, num2.integer, result.integer);
  }
  else {
    printf("%f %c %f = %f", num1.double_number, oprt1, num2.double_number, result.double_number);
  }
  printf("\n");
  return 0;
}