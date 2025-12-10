#include "token.h"

std::string Token::to_string() const{
    return tokentype_to_string(toke_type) + " " + lexeme + " " + std::any_cast<std::string>(obj);     
}