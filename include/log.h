#pragma once
#ifndef __LOG_H__
#define __LOG_H__

#include <iostream>
#include <string>

class Log{

    public:
    static void info(const std::string& msg){
        std::cout<<msg<<std::endl;
    }

    static void err(const size_t line, const std::string& msg){
        std::cout<<"["<<line<<"] : "<<msg<<std::endl;
    }

};


#endif