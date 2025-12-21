#include "token.h"

std::string Token::to_string() const
{
    std::string literal = std::visit([](auto&& arg)->std::string{
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, std::monostate>){
            return "null";
        }
        else if constexpr(std::is_same_v<T,double>){
            return std::to_string(arg);
        }
        else if constexpr(std::is_same_v<T,std::string>){
            return arg;
        }
        else if constexpr(std::is_same_v<T,int>){
            return std::to_string(arg);
        }
        else if constexpr(std::is_same_v<T,bool>){
            return arg?"true":"false";
        }
        else{
            return "unknown";
        }
    },obj);
    
    return "["+ tokentype_to_string(token_type) + "], [" + lexeme + "], [" + literal + "], [" + std::to_string(line)+"]";
}