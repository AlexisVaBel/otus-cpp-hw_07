#include "strhelper.h"

#include <algorithm>
char get_head_str(std::string str){
    return str.substr(0,1).c_str()[0];
}

char get_last_str(std::string str){
    return str.substr(str.length()-1,1).c_str()[0];
}

std::string get_tail_str(std::string str){
    return str.substr(1,str.length()-1);
}

std::string get_matched(std::string fst, std::string snd){
    return std::string(fst.begin(),std::mismatch(fst.begin(),fst.end(),snd.begin(),snd.end()).first);
}

std::string get_mismatched(std::string fst, std::string snd){
    return std::string(std::mismatch(fst.begin(),fst.end(),snd.begin(),snd.end()).first , fst.end());
}
