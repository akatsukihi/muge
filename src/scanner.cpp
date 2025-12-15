#include "scanner.h"

/**
 * 关键字定义
 */
std::unordered_map<std::string, TokenType> Scanner::key_words = {
    {"and", TokenType::AND},
    {"class", TokenType::CLASS},
    {"else", TokenType::ELSE},
    {"false", TokenType::FALSE},
    {"for", TokenType::FOR},
    {"fun", TokenType::FUN},
    {"if", TokenType::IF},
    {"nil", TokenType::NIL},
    {"or", TokenType::OR},
    {"print", TokenType::PRINT},
    {"return", TokenType::RETURN},
    {"super", TokenType::SUPER},
    {"this", TokenType::THIS},
    {"true", TokenType::TRUE},
    {"var", TokenType::VAR},
    {"while", TokenType::WHILE}
};


/**
 * 是否是文件结尾
 */
bool Scanner::is_end() const{
    return current >= src.length();
}

/**
 * 解析文本
 */
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

/**
 * 解析结果按类型放入集合
 */
void Scanner::put_token(const TokenType& tktype, const std::any& obj){
    std::string s = src.substr(start,current-start);
    tokens.emplace_back(tktype,s,obj,line);
}

/**
 * 返回当前字符，并将读取索引+1
 */
unsigned char Scanner::read_char(){
    current++;
    return src.at(current-1);
}

/**
 * 字符分析归类
 */
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
        case '!':put_token(is_pair('=')?TokenType::EXCLAMATION_EQUAL:TokenType::EXCLAMATION);break;
        case '=':put_token(is_pair('=')?TokenType::EQUAL_EQUAL:TokenType::EQUAL);break;
        case '<':put_token(is_pair('=')?TokenType::LESS_EQUAL:TokenType::LESS);break;
        case '>':put_token(is_pair('=')?TokenType::GREATER_EQUAL:TokenType::GREATER);break;
        case '/':
            if(is_pair('/')){
                while(!is_end() && next_char()!='\n')
                    read_char();
            }else{
                put_token(TokenType::SLASH);
            }
            break;
        case ' ':
        case '\t':
        case '\r':break;
        case '\n':line++;break;
        case '"':get_literal();break;
        default:
            if(is_number(c)){
                get_number();
            }else if(is_alpha(c)){
                identifier();
            }else{
                Log::err(line,"Unexpected character.");
            }
            break;
    }
}

/**
 * 是否是复合型
 */
bool Scanner::is_pair(const unsigned char& c){
    if(is_end()){
        return false;
    }
    if(c != src.at(current)) 
        return false;
    current++;
    return true;
}

/**
 * 获取下一个字符
 */
unsigned char Scanner::next_char() const{
    if(is_end()){
        return '\0';
    }
    return src.at(current);
}

/**
 * 获取下2个字符
 */
unsigned char Scanner::next_2char() const{
    if((current+1)>=src.length()){
        return '\0';
    }
    return src.at(current+1);
}

/**
 * number check
 */
bool Scanner::is_number(const unsigned char& c) const{
    return c>='0' && c<='9';
}

/**
 * 获取字符串字面量
 */
void Scanner::get_literal(){
    bool flg = false;
    unsigned int cnt = 0;
    while(!is_end() && next_char() != '"'){
        if(next_char() == '\n'){
            line++;
            cnt++;
            flg = true;
        }
        read_char();
    }
    if(is_end()){
        Log::err(flg?line-cnt:line,"The [\"] characters are not paired");
        return;
    }
    read_char();
    std::string str = src.substr(start+1,current-start-2);
    put_token(TokenType::STRING,str);
}


/**
 * 获取数字
 */
void Scanner::get_number(){
    while(is_number(next_char())){
        read_char();
    }
    if(next_char() == '.' && is_number(next_2char())){
        read_char();
        while(is_number(next_char())) read_char();
    }
    put_token(TokenType::NUMBER,src.substr(start,current));
}

/**
 * 关键字，标识符解析
 */
void Scanner::identifier(){
    while(is_alpha_number(next_char()))
        read_char();
    TokenType ttype = TokenType::IDENTIFIER;
    std::string key = src.substr(start,current-start);
    auto kwd = key_words.find(key);
    if(kwd != key_words.end()){
        ttype = kwd->second;
    }
    put_token(ttype);
}


/**
 * 字母check
 */
bool Scanner::is_alpha(const unsigned char& c) const{
    return (c>='a' && c<='z') || (c>='A' && c<='Z') || c == '_'; 
}

/**
 * 标识符check
 */
bool Scanner::is_alpha_number(const unsigned char& c) const{
    return is_alpha(c) || is_number(c);
}