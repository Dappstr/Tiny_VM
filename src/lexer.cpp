#include <string>
#include <vector>
#include <iostream>

#include "../include/lexer.hpp"

std::vector<std::string> lex(const std::string& source) {
    std::vector<std::string> lexemes;
    std::string lexeme;

    for(int i = 0; i < source.length(); ++i) {
        if(isspace(source.at(i))) {
            if(!lexeme.empty()) {
                lexemes.push_back(lexeme);
                lexeme.clear();
            }
            continue;
        }
        else if(isalpha(source.at(i))) {
            while(isalpha(source.at(i))) {
                lexeme.push_back(source.at(i));
                ++i;
            }
            --i;
            lexemes.push_back(lexeme);
            lexeme.clear();
        }
        else if(isdigit(source.at(i))) {
            while(isdigit(source.at(i))) {
                lexeme.push_back(source.at(i));
                ++i;
            }
            --i;
            lexemes.push_back(lexeme);
            lexeme.clear();
        }
        else if(source.at(i) == '#') {
            lexeme.push_back(source.at(i));
            lexemes.push_back(lexeme);
            lexeme.clear();
        }
        else {
            std::cerr << "Encountered unexpected lexeme while lexing!\n";
            exit(EXIT_FAILURE);
        }
    }

    return lexemes;
}
