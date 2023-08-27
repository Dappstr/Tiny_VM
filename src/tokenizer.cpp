#include <string>
#include <vector>
#include <variant>
#include <iostream>

#include "../include/tokenizer.hpp"

std::vector<Token> tokenize(const std::vector<std::string> &lexemes) {
    std::vector<Token> tokens;

    for(int i = 0; i < lexemes.size(); ++i) {
        if(lexemes.at(i) == "add") {
            tokens.push_back({Type::INST, Inst_type::ADD});
        }
        else if(lexemes.at(i) == "sub") {
            tokens.push_back({Type::INST, Inst_type::SUB});
        }
        else if(lexemes.at(i) == "mul") {
            tokens.push_back({Type::INST, Inst_type::MUL});
        }
        else if(lexemes.at(i) == "push") {
            tokens.push_back({Type::INST, Inst_type::PUSH});
        }
        else if(lexemes.at(i) == "pop") {
            tokens.push_back({Type::INST, Inst_type::POP});
        }
        else if(lexemes.at(i) == "#") {
            if(i + 1 < lexemes.size()) {
                try {
                    int value = std::stoi(lexemes.at(i+1));
                    tokens.push_back({Type::NUM, value});
                    i++;
                }
                catch(const std::invalid_argument& e) {
                    std::cout << "Failed to get number after '#'" << '\n' << e.what() << '\n';
                    exit(EXIT_FAILURE);
                }
            }
        }
    }

    return tokens;
}
