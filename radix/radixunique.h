#ifndef RADIXUNIQUE_H
#define RADIXUNIQUE_H

#include <strhelper.h>
#include <memory>
#include <iostream>

namespace  radixnode_un{


static const  size_t ALPHABET_PWR     = 26; // 26 english alphabet
static const  size_t CODE_OF_SML_A    = 97;
static const  size_t MAX_SIZE_LABEL   = 256;

struct RadixUnique{
    int  is_end;
    bool is_initialized;                // for holding only if have childs
    std::unique_ptr<char[]> m_lbl;
    std::unique_ptr<RadixUnique[]> m_childs;

    ~RadixUnique(){
    }

    RadixUnique():is_initialized(false){
        m_lbl    = std::unique_ptr<char[]>(new char[MAX_SIZE_LABEL]);
    }

    void addChild(char chpos, std::string str, int iend ){
        if(! is_initialized ){
            m_childs         = std::unique_ptr<RadixUnique[]> (new RadixUnique[ALPHABET_PWR]);
            is_initialized   = true;
        }

        size_t ipos = chpos - CODE_OF_SML_A;

        m_childs[ipos].is_end = iend;

        auto ch = &m_childs[ipos].m_lbl[0];
        str.copy(ch,str.length(),0);

    }

    RadixUnique *getNode(char chpos){
        size_t ipos = chpos - CODE_OF_SML_A;

        if(is_initialized){                        
            return &m_childs[ipos];
        }
        else return nullptr;
    }

    bool hasChildren(){
        if(!is_initialized) return false;
        for(size_t ipos = 0; ipos < ALPHABET_PWR; ++ipos){
            if(get_head_str(m_childs[ipos].m_lbl.get()) - CODE_OF_SML_A >= 0) return true;
        }
        return false;
    }
};

}

#endif // RADIXUNIQUE_H
