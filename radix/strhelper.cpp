#include "strhelper.h"

#include <algorithm>

unsigned char get_head_str(const std::string &str){
    return str.front();
}

std::string get_tail_str(const std::string &str){
    return str.substr(1,str.length()-1);
}

std::string get_matched(const std::string &fst, const std::string &snd){
    return std::string(fst.begin(),std::mismatch(fst.begin(),fst.end(),snd.begin(),snd.end()).first);
}

std::string get_mismatched(const std::string &fst, const std::string &snd){
    return std::string(std::mismatch(fst.begin(),fst.end(),snd.begin(),snd.end()).first , fst.end());
}
