#pragma once
#ifndef __ARENA_AST_H__
#define __ARENA_AST_H__

#include <vector>
#include "expre_ast.h"

class Arena{


    public:
    ~Arena(){
        for(auto node:nodes){
            delete node;
        }
    }

    template<typename T, typename... Args>
    T* create(Args&&... args){
        T* node = new T(std::forward<Args>(args)...);
        nodes.push_back(node);
        return node;
    }



    private:
    std::vector<expre_ptr> nodes;
};


#endif