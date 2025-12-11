#include "scanner.h"

bool Scanner::is_end() const{
    return current >= src.length();
}

std::vector<Token> Scanner::scan_tokens(){
    while(!is_end()){
        start = current;
        scan_token();
    }
    tokens.emplace_back(TokenType::END_OF_FILE,"",nullptr,line);
    return tokens;
}

void Scanner::put_token(const TokenType& tktype){
    put_token(tktype,nullptr);
}

void Scanner::put_token(const TokenType& tktype, const std::any& obj){
    std::string s = src.substr(start,current-start);
    tokens.emplace_back(tktype,s,obj,line);
}

unsigned char Scanner::read_char(){
    current++;
    return src.at(current-1);
}

void Scanner::scan_token(){
    unsigned char c = read_char();
    switch (c){
        case '(':put_token(TokenType::LEFT_PAREN);break;
        case ')':put_token(TokenType::RIGHT_PAREN);break;
        case '{':put_token(TokenType::LEFT_BRACE);break;
        case '}':put_token(TokenType::RIGHT_BRACE);break;
        case ',':put_token(TokenType::COMMA);break;
        case '.':put_token(TokenType::DOT);break;
        case '-':put_token(TokenType::MINUS);break;
        case '+':put_token(TokenType::PLUS);break;
        case ';':put_token(TokenType::SEMICOLON);break;
        case '*':put_token(TokenType::STAR);break;
        case '\r':break;
        case '\n':line++;break;
        default:
            Log::err(line,"Unexpected character.");
            break;
    }
}

bool Scanner::is_pair(unsigned char c){
    if(is_end()){
        return false;
    }
    current++;
    return c==src.at(current-1);
}