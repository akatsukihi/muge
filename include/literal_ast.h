#pragma once
#ifndef __LITERAL_H__
#define __LITERAL_H__


#include "expre_ast.h"
#include "data_type.h"

class Literal:Expre{

    public:
    explicit Literal(LiteralValue lv):lv(std::move(lv)){};

    void accept(ExpreVisitor& visitor) const override{
        visitor.visitor_literal(*this);   
    }

    const LiteralValue& get_literal_value() const { return lv; }

    private:
    LiteralValue lv;
};




#endif