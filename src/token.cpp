#include "token.h"

std::string Token::to_string() const
{
    std::string literal;
    if (obj.type() == typeid(std::nullptr_t))
    {
        literal = "null";
    }
    else if (obj.type() == typeid(std::string))
    {
        literal = std::any_cast<std::string>(obj);
    }
    else if (obj.type() == typeid(double))
    {
        literal = std::to_string(std::any_cast<double>(obj));
    }
    else if (obj.type() == typeid(int))
    {
        literal = std::to_string(std::any_cast<int>(obj));
    }
    else
    {
        literal = "unknown";
    }
    return "["+ tokentype_to_string(toke_type) + "], [" + lexeme + "], [" + literal + "], [" + std::to_string(line)+"]";
}