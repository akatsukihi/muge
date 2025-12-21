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

    const expre_ptr& get_left() const { return left; }
    const std::string& get_opt() const { return opt; }
    const expre_ptr& get_right() const { return right; }

    private:
    expre_ptr left;
    std::string opt;
    expre_ptr right;

};


#endif