#pragma once
#ifndef __EXPRE_AST_H__
#define __EXPRE_AST_H__

#include <memory>
#include <string>

class Binary;
class Group;
class Literal;
class Unary;


class ExpreVisitor{
    public:
    virtual ~ExpreVisitor() = default;
    virtual void visitor_binary(const Binary& expre)=0;
    virtual void visitor_group(const Group& expre)=0;
    virtual void visitor_literal(const Literal& expre)=0;
    virtual void visitor_unary(const Unary& expre)=0;
};



class Expre{
    public:
    virtual ~Expre() = default;
     
    virtual void accept(ExpreVisitor& visitor) const = 0;
};

using expre_ptr = std::unique_ptr<Expre>;
#endif