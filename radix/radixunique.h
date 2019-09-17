#ifndef RADIXUNIQUE_H
#define RADIXUNIQUE_H

#include <strhelper.h>

#include <array>
#include <memory>
#include <iostream>

namespace  radixnode_un{


static const  size_t MAX_CNT_CHILDS   = 256;

struct RadixUnique{
    int  is_end{0};
    std::string m_lbl;

    std::array<std::unique_ptr<RadixUnique>, MAX_CNT_CHILDS> m_childs;

    ~RadixUnique(){
    }

    RadixUnique(){
        m_lbl = "";
    }

    void addChild(char chpos, std::string str, int iend ){
        size_t ipos = chpos;
        if(chpos >= MAX_CNT_CHILDS) return;
        m_childs.at(ipos) =  std::unique_ptr<RadixUnique>(new RadixUnique());
        m_childs.at(ipos)->is_end = iend;
        m_childs.at(ipos)->m_lbl = str;

    }

    RadixUnique *getNode(char chpos){
        size_t ipos = chpos;
        if(chpos >= MAX_CNT_CHILDS) return nullptr;
        return m_childs.at(ipos).get();
    }

    bool hasChildren(){        
        for(size_t ipos = 0; ipos < MAX_CNT_CHILDS; ++ipos){
            if(m_childs.at(ipos).get() != nullptr && (! m_childs.at(ipos)->m_lbl.empty())) return true;
        }
        return false;
    }
};

}

#endif // RADIXUNIQUE_H
