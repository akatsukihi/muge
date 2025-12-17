#pragma once
#ifndef __LITERAL_H__
#define __LITERAL_H__


#include <variant>
#include "expre_ast.h"

using LiteralValue = std::variant<double,std::string,bool,std::monostate>;

class Literal:Expre{

    public:
    explicit Literal(LiteralValue lv):lv(std::move(lv)){};

    void accept(ExpreVisitor& visitor) const override{
        visitor.visitor_literal(*this);   
    }

    private:
    LiteralValue lv;

};




#endif