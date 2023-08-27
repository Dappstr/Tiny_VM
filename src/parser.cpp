#include <algorithm>
#include <iostream>
#include <vector>

#include "../include/parser.hpp"
#include "../include/tokenizer.hpp"

void parse(const std::vector<Token> &tokens, std::vector<int> &stack) {
    for(int i = 0; i < tokens.size(); ++i) {
        if(tokens.at(i).m_type == Type::INST) {
           Inst_type inst = std::get<Inst_type>(tokens.at(i).m_value);
           switch(inst) {
               case Inst_type::PUSH: {
                    if(tokens.at(i+1).m_type != Type::NUM) {
                        std::cerr << "Expected number after push!\n";
                        exit(EXIT_FAILURE);
                    }
                    else {
                        int value = std::get<int>(tokens.at(i+1).m_value);
                        stack.push_back(value);
                        std::cout << "Pushed " << value << " to stack\n";
                    }
                    break;
               }
               case Inst_type::POP: {
                    if(stack.size() < 1) {
                        break;
                    }
                    else {
                        //Shift left
                        for(int x = 1; x < stack.size(); ++x) {
                            stack[x - 1] = stack[x];
                        }
                        stack.pop_back();
                    }
                    break;
               }
               case Inst_type::PRINT: {
                    std::cout << "[ ";
                    for(int x = 0; x < stack.size(); ++x) {
                        if(x == stack.size() - 1) {
                            std::cout << stack.at(x) << " ]";
                            break;
                        }
                        std::cout << stack.at(x) << ", ";
                    }
                    std::cout << '\n';
               }
               case Inst_type::ADD: {
                    int total = 0;
                    for(int x = 0; x < stack.size(); x++) {
                        total += stack.at(x);
                    }
                    std::cout << total << '\n';
                    break;
               }
               case Inst_type::SUB: {
                    int total = stack.at(0);
                    if(stack.size() > 1) {
                        for(int x = 0; x < stack.size(); ++x) {
                            total -= stack.at(x);
                        }
                        std::cout << total;
                    }
               }
               case Inst_type::MUL: {
                    int total = stack.at(0);
                    if(stack.size() > 1) {
                        for(int x = 1; x < stack.size(); ++x) {
                            total *= stack.at(x);
                        }
                    }
                    std::cout << total;
                    break;
               }
               case Inst_type::HLT: {
                    stack.clear();
                    exit(EXIT_SUCCESS);
               }
           }
        }
    }
}
