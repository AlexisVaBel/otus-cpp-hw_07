#ifndef STRHELPER_H
#define STRHELPER_H


#include <string>

char get_head_str(std::string str);

char get_last_str(std::string str);

std::string get_tail_str(std::string str);

std::string get_matched(std::string fst, std::string snd);

std::string get_mismatched(std::string fst, std::string snd);

#endif // STRHELPER_H
