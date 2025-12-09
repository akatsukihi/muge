#include "scanner.h"

std::vector<Token> Scanner::scan_token(){
    while(!is_end()){
        start = current;
        scan_token();
    }
    tokens.emplace_back(TokenType::END_OF_FILE,"",line,nullptr);
    return tokens;
}