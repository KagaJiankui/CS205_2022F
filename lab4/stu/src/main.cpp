#include "stuinfo.h"

int main(int argc, char const *argv[])
{
  const int     n = 5;
  const char    ch[] = "Wang XiaoMing";
    stuinfo       s[n];
  inputstu(s, n);
  showstu(s, n);
  sortstu(s, n);
  showstu(s, n);
  bool fl = findstu(s, n, ch);
  if(fl){
    std::cout << "Student " << ch << " is in the list" << std::endl;
  }
  else {
    std::cout << "Student " << ch << " is NOT in the list" << std::endl;
  }
  return 0;
}
