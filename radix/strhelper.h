#ifndef STRHELPER_H
#define STRHELPER_H


#include <string>

unsigned char get_head_str(const std::string &str);



std::string get_tail_str(const std::string &str);

std::string get_matched(const std::string &fst, const std::string &snd);

std::string get_mismatched(const std::string &fst, const std::string &snd);

#endif // STRHELPER_H
