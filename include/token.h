#pragma once
#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <iostream>
#include <string>
#include "token_type.h"
#include "log.h"
#include "data_type.h"

class Token{

    public:
    Token(TokenType token_type,std::string lexeme,LiteralValue obj,size_t line):token_type(token_type),lexeme(std::move(lexeme)),obj(obj),line(line){};
    std::string to_string() const;

    private:
    const std::string lexeme;
    const TokenType token_type;
    const size_t line;
    const LiteralValue obj;
    inline std::string tokentype_to_string(const TokenType& tktype)const{
        switch (tktype){
            case TokenType::LEFT_PAREN:return "left round brackets";
            case TokenType::RIGHT_PAREN:return "right round brackets";
            case TokenType::LEFT_BRACE:return "left curly brackets";
            case TokenType::RIGHT_BRACE:return "right curly brackets";
            case TokenType::COMMA:return "comma";
            case TokenType::DOT:return "dot";
            case TokenType::MINUS:return "minus";
            case TokenType::PLUS:return "plus";
            case TokenType::SEMICOLON:return "semicolon";
            case TokenType::SLASH:return "slash";
            case TokenType::STAR:return "star";
            case TokenType::EXCLAMATION:return "exclamation point";
            case TokenType::EXCLAMATION_EQUAL:return "not equal";
            case TokenType::EQUAL:return "equal";
            case TokenType::EQUAL_EQUAL:return "equal equal";
            case TokenType::GREATER:return "greater";
            case TokenType::GREATER_EQUAL:return "greater equal";
            case TokenType::LESS:return "less";
            case TokenType::LESS_EQUAL:return "less equal";
            case TokenType::IDENTIFIER:return "identifier";
            case TokenType::STRING:return "string";
            case TokenType::NUMBER:return "number";
            case TokenType::AND:return "and";
            case TokenType::CLASS:return "class";
            case TokenType::ELSE:return "else";
            case TokenType::FALSE:return "false";
            case TokenType::FUN:return "function";
            case TokenType::FOR:return "for";
            case TokenType::IF:return "if";
            case TokenType::NIL:return "null";
            case TokenType::OR:return "or";
            case TokenType::PRINT:return "print";
            case TokenType::RETURN:return "return";
            case TokenType::SUPER:return "super";
            case TokenType::THIS:return "this";
            case TokenType::TRUE:return "true";
            case TokenType::VAR:return "var";
            case TokenType::WHILE:return "while";
            case TokenType::END_OF_FILE:return "end of file";
        }
        return "unknown";
    }
};

#endif