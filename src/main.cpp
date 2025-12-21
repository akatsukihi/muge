#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "scanner.h"
#include "print_ast.h"


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

    // if(argc < 2){
    //     std::cerr<<"Usage: muge.exe [file]\n";
    //     return 1;
    // }
    // std::string file_name(argv[1]);
    std::string file_name("C:/Users/xiao3/Desktop/test.txt");
    try{
       std::string file = read_file(file_name);
       Scanner sc(file);
       std::vector<Token> tokens = sc.scan_tokens();
       for(auto x : tokens){
            std::cout<<x.to_string()<<std::endl;
       }

       // print AST test
       auto expre = std::make_unique<Binary>(
            std::make_unique<Unary>(
                std::make_unique<Literal>(42.0),
                "-"
            ),
            "*",
            std::make_unique<Group>(
                std::make_unique<Literal>(3.14)
            )
       );
       PrintAst printast;
       expre->accept(printast);
       std::cout<<"AST print result: "<<printast.result<<"\n";



    }catch(const std::exception& e){
        std::cerr<<"Error:"<<e.what()<<"\n";
        return 1;
    }

    return 0;
}


