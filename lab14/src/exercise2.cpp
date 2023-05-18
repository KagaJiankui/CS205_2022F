#include "exercise2.h"

float calculateAverage(int *marks,int len) {
  float sum = 0;
  for (int i = 0; i < len; i++) {
    if (marks[i]<0||marks[i]>100)
    {
      throw OutOfRangeException(i+1, marks[i]);
    }
    sum+=marks[i];
  }
  return sum/(float) len;
}

int main(int argc, char const *argv[]) {
  char flag_c;
  int length=4;
  int *marks = new int[length];
  while (std::cin.fail() == false) {
    std::cout << "Please enter marks for 4 courses: ";
    std::cin >> marks[0] >> marks[1] >> marks[2] >> marks[3];
    try {
      std::cout << " The average of the four marks is " << calculateAverage(marks,length)<<std::endl;
    } catch (OutOfRangeException &e) {
      std::cerr << "The parameter " << e.getPos() << " is " << e.getVal() << " which out of range (0-100)" << std::endl;
    }
    std::cout << "Would you want to enter another marks for 4 courses(y/n)?";
    std::cin >> flag_c;
    if (flag_c!='y')
    {
      break;
    }
  }
  return 0;
}
