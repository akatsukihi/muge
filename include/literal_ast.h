#pragma once
#ifndef __LITERAL_H__
#define __LITERAL_H__


#include <any>
#include "expre_ast.h"

class Literal:Expre{

    public:
    explicit Literal(std::any lv):lv(std::move(lv)){};

    void accept(ExpreVisitor& visitor) const override{
        visitor.visitor_literal(*this);   
    }

    private:
    std::any lv;

};




#endif