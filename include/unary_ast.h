#pragma once
#ifndef __UNARY_H__
#define __UNARY_H__

#include "expre_ast.h"

class Unary:Expre{

    public:
    Unary(expre_ptr right, std::string opt):right(std::move(right)),opt(std::move(opt)){}

    void accept(ExpreVisitor& visitor) const override{
        visitor.visitor_unary(*this);
    }
    const std::string& get_opt() const { return opt; }
    const expre_ptr& get_right() const { return right; }

    private:
    std::string opt;
    expre_ptr right;
};


#endif