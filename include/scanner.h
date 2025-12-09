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
    std::vector<Token> scan_token();
    inline bool is_end() const{
        return current >= src.length();
    }


    private:
    const std::string src;
    std::vector<Token> tokens;
    int current = 0;
    int start = 0;
    int line = 1;
};


#endif