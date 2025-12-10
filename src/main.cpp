#include <iostream>
#include <fstream>
#include <string>
#include "scanner.h"


std::string read_file(const std::string& s){
    std::ifstream fd(s,std::ios::in | std::ios::binary);
    if (!fd.is_open()){
        throw std::runtime_error("failed open file:"+s);
    }
    fd.seekg(0,std::ios::end);
    size_t len = fd.tellg();
    std::string buff(len,'\0');
    fd.seekg(0,std::ios::beg);
    fd.read(&buff[0],len);
    return buff;
}


int main(int argc, char* argv[]) {

    if(argc < 2){
        std::cerr<<"Usage: muge.exe [file]\n";
        return 1;
    }
    std::string file_name(argv[1]);
    try{
       std::string file = read_file(file_name);
       Scanner sc(file);
       std::vector<Token> tokens = sc.scan_tokens();
       for(auto x : tokens){
            x.to_string();
       }

    }catch(const std::exception& e){
        std::cerr<<"Error:"<<e.what()<<"\n";
        return 1;
    }

    return 0;
}


