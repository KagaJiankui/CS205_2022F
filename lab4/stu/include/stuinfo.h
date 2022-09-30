#pragma once
#include <iostream>
#include <string>
struct stuinfo
{
  char   name[20];
  double score[3];
  double ave;
};
/**
 * @brief asks the user to enter each of the preceding items of information to set the corresponding members of the structure.
 *
 * @param stu
 * @param n
 */
void inputstu(stuinfo stu[], int n);

/**
 * @brief displays the contents of the structure, one student one line.
 *
 * @param stu
 * @param n
 */
void showstu(stuinfo stu[], const int n);

/**
 * @brief sorts in descending order of  average of three scores. Quick sort algorithm is utilized.
 *
 * @param stu
 * @param n
 */
void sortstu(stuinfo stu[], const int n);

/**
 * @brief finds if given characters is the student’s name.
 *
 * @param stu
 * @param n
 * @param ch
 * @return true
 * @return false
 */
bool findstu(stuinfo stu[], const int n, const char ch[]);