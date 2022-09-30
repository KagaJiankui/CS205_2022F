#include "stuinfo.h"
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <regex>

/**
 * @brief Evaluate the average of the score.
 *
 * @param score
 * @return double
 */
double average(const double* score)
{
  return (score[0] + score[1] + score[2]) / 3.0;
}

bool cmpAve(stuinfo stu1,stuinfo stu2){
    return stu1.ave>stu2.ave;
}
void inputstu(stuinfo* stu, const int n)
{
  std::string strTobeProcessed, ScoreData;
  std::regex  regName_Data(R"((.*),\s?\[(.*)\])");
  std::regex  tok(",");
  std::smatch s;
  for (int i = 0; i < n; i++) {
    std::cout << "Student [" << i << "] NAME,[SCORES]>";
    std::getline(std::cin, strTobeProcessed);
    auto ret = std::regex_match(strTobeProcessed, s, regName_Data);
    strncpy(stu[i].name, s[1].str().c_str(), 20);
    ScoreData = s[2].str();
    std::sregex_token_iterator pos(ScoreData.begin(), ScoreData.end(), tok, -1);
    decltype(pos)              end;
    int                        j = 0;
    for (; pos != end; ++pos) {
      stu[i].score[j] = std::stod(pos->str());
      j++;
    }
    stu[i].ave = average(stu[i].score);
  }
}

void showstu(stuinfo* stu, const int n)
{
  for (int i = 0; i < n; ++i) {
    std::cout << "Student [" << i << "]:" << stu[i].name << std::endl;
    std::cout << " Score:[";
    for (int j = 0; j < 3; ++j) {
      std::cout <<std::fixed<< std::setprecision(2) << stu[i].score[j] << ",";
    }
    std::cout << "\b]";
    std::cout << " Average:" <<std::fixed<< std::setprecision(2) << stu[i].ave << std::endl;
  }
}

void sortstu(stuinfo *stu, const int n){
  std::sort(stu, stu + n, cmpAve);
}

bool findstu(stuinfo *stu, const int n, const char *ch){
  // char ch_tmp[20];
  // strncpy(ch_tmp, ch, 20);
  for (int i = 0; i < n; ++i) {
    int m = strcmp(stu[i].name, ch);
    // std::cout << m << " ";
    if (!((bool)m)) {
      return true;
    }
  }
    return false;
}