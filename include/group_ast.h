#pragma once
#ifndef __GROUP_H__
#define __GROUP_H__

#include "expre_ast.h"

class Group:Expre{

    public:
    explicit Group(expre_ptr expre):expre(std::move(expre)){}

    void accept(ExpreVisitor& visitor) const override{
        visitor.visitor_group(*this);
    }


    private:
    expre_ptr expre;
};




#endif