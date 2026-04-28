#include "Lexer.h"

std::vector<std::string> cutString(const std::string& s){
    std::vector<std::string> tab;
    size_t start = 0;
    while (true) {
        size_t pos = s.find(' ', start);
        if (pos == std::string::npos) {
            tab.emplace_back(s.substr(start));            
            break;
        }

        tab.emplace_back(s.substr(start, pos - start));
        start = pos + 1;        
    }
    return tab;
}

std::vector<Token> lexer(const std::string& s){
    std::string temp;
   
    std::vector<Token> tokens;
    std::vector<std::string> tab = cutString(s);
    
    for(const auto& token:tab){        
        char* end;
        std::strtod(token.c_str(), &end);
        if (*end == '\0') {
            tokens.emplace_back(Token(TokenType::Constant,token));            
        }
        else if(token=="+" || token=="-" || token=="/" || token=="*"){
            tokens.emplace_back(Token(TokenType::BinaryOperator,token));
            
        }else if(token == "~"){
            tokens.emplace_back(Token(TokenType::UnaryOperator,token));
        }      
        else{
            bool isVariable = true;
            if(!token.empty()  && (std::isalpha(token[0]) || token[0] == '_')){
                for(auto c:token){
                    if(!std::isalnum(c) && c!='_'){
                        isVariable = false;
                        break;
                    }                    
                }
                if(isVariable){
                    tokens.emplace_back(Token(TokenType::Variable,token)); 
                   
                }
            }
        }
    }
    return tokens;
}

