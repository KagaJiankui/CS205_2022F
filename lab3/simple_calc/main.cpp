#include <iostream>

int eval_result(char symbol, int a, int b, int* flag_error);
int main(int  /*argc*/, const char**  /*argv*/) {
  char sym = 0;
  int op1 = 0, op2 = 0, result = 0, flag_err = 0;
  while (true) {
    std::cout << "Please select an operation:" << std::endl;
    std::cout << "+, -, *, /, % >";
    std::cin >> sym;
    if ((sym != '+') && (sym != '-') && (sym != '*') && (sym != '/') &&
        (sym != '%')) {
      std::cout << "Invalid operator!" << std::endl;
      continue;
    }
    std::cout << "Please input 2 operands:";
    std::cin >> op1 >> op2;
    result = eval_result(sym, op1, op2, &flag_err);
    while (flag_err == -2) {
      std::cout << "The dividend can no be 0,please input the dividend again."
                << std::endl;
      std::cin >> op2;
      result = eval_result(sym, op1, op2, &flag_err);
    }
    std::cout << op1 << " " << sym << " " << op2 << " = " << result
              << std::endl;
    std::cout << "Do you want to continue?(Y/N)";
    char yn = 0;
    std::cin >> yn;
    if ((yn == 'N') || (yn == 'n')) {
      break;
    }
  }
  return 0;
}

int eval_result(char symbol, int a, int b, int* flag_error) {
  int result = 0;
  *flag_error = 0;
  switch (symbol) {
    case '+':
      result = a + b;
      break;
    case '-':
      result = a - b;
      break;
    case '*':
      result = a * b;
      break;
    case '/':
      if (b == 0) {
        std::cerr << "Dividend is zero!";
        *flag_error = -2;
      } else {
        result = a / b;
      }
      break;
    case '%':
      if (b == 0) {
        std::cerr << "Dividend is zero!";
        *flag_error = -2;
      } else {
        result = a % b;
      }
      break;
    default:
      std::cerr << "Invalid operator!";
      *flag_error = -1;
  }
  return result;
}