#pragma once
#ifndef __BINARY_H__
#define __BINARY_H__

#include "expre_ast.h"

class Binary:Expre{

    public:
    Binary(expre_ptr left,std::string opt, expre_ptr right):left(std::move(left)),opt(std::move(opt)),right(std::move(right)){}

    void accept(ExpreVisitor& visitor) const override{
        visitor.visitor_binary(*this);
    }

    private:
    expre_ptr left;
    std::string opt;
    expre_ptr right;

};


#endif