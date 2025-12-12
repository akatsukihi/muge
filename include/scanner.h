#pragma once
#ifndef __SCANNER_H__
#define __SCANNER_H__

#include <iostream>
#include <string>
#include <vector>
#include "token.h"

class Scanner{

    public:
    Scanner(std::string source):src(std::move(source)){}
    std::vector<Token> scan_tokens();


    private:
    const std::string src;
    std::vector<Token> tokens;
    size_t current = 0;
    size_t start = 0;
    size_t line = 1;
    bool is_end() const;
    void scan_token();
    unsigned char read_char();
    void put_token(const TokenType& tktype);
    void put_token(const TokenType& tktype,const std::any& obj);
    bool is_pair(unsigned char c);
    unsigned char next_char() const;
    unsigned char next_2char() const;
    void get_literal();
    bool is_number(unsigned char c) const;
    void get_number();
};


#endif