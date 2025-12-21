#pragma once
#ifndef __PRINT_AST_H__
#define __PRINT_AST_H__

#include <sstream>
#include "binary_ast.h"
#include "group_ast.h"
#include "literal_ast.h"
#include "unary_ast.h"


class PrintAst: public ExpreVisitor{

    public:
    std::string result;

    void visitor_binary(const Binary& expre) override{
        print_helper(expre.get_opt(), *expre.get_left(), *expre.get_right());
    }

    void visitor_group(const Group& expre) override{
        print_helper("group", *expre.get_expre());
    }

    void visitor_unary(const Unary& expre) override{
        print_helper(expre.get_opt(), *expre.get_right());
    }

    void visitor_literal(const Literal& expre) override{
        std::visit([this](auto&& arg){
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, std::monostate>){
                result += "null";
            }
            else if constexpr(std::is_same_v<T,double>){
                result += std::to_string(arg);
            }
            else if constexpr(std::is_same_v<T,std::string>){
                result += arg;
            }
            else if constexpr(std::is_same_v<T,int>){
                result +=  std::to_string(arg);
            }
            else if constexpr(std::is_same_v<T, bool>){
                result += arg? "true":"false";
            }else{
                result += "error unknown type";
            }
        },expre.get_literal_value());
    }


    private:
    template<typename... Expre>
    void print_helper(const std::string& name, const Expre&... expre){
        result += "(" + name;
        ((result += " ",expre.accept(*this)), ...);
        result += ")";
    }

};



#endif