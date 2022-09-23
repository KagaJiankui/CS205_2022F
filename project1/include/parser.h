#pragma once
#include<cctype>
#include<cstring>

void two_word_parser(char* str, int* examine);
inline int flag_NaN(char c);
inline int flag_Ee(char c);
inline int flag_pm(char c);