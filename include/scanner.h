#pragma once
#ifndef __SCANNER_H__
#define __SCANNER_H__

#include <iostream>
#include <string>
#include <vector>

class Scanner{

    public:
    Scanner(std::string source):src(std::move(source)){}
    std::vector<std::string>& scan_token();
    inline bool is_end() const{
        return current >= src.length();
    }


    private:
    const std::string src;
    const std::vector<std::string> tokens;
    int current = 0;
    int start = 0;
    int line = 1;
};


#endif