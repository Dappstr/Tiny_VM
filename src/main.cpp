#include <__iterator/concepts.h>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <vector>

#include "../include/fileutil.hpp"
#include "../include/lexer.hpp"
#include "../include/tokenizer.hpp"

int main(int argc, char* argv[]) {
    
    if(argc < 2) {
        std::cerr << "USAGE: " << argv[0] << " <path_to_file>\n";
        exit(EXIT_FAILURE);
    }

    //get file contents
    char* path = argv[1];
    std::string contents = get_file_contents(path);

    //lex
    std::vector<std::string> lexemes = lex(contents);
    
    //tokenize
    std::vector<Token> tokens = tokenize(lexemes);
    for(auto token : tokens) {
        if(token.m_type == Type::INST) {
            std::cout << "Token type: INST, ";
            Inst_type inst_type = std::get<Inst_type>(token.m_value);
            switch(inst_type) {
                case Inst_type::ADD:
                    std::cout << "ADD\n";
                    break;

                case Inst_type::SUB:
                    std::cout << "SUB\n";
                    break;

                case Inst_type::MUL:
                    std::cout << "MUL\n";
                    break;

                case Inst_type::PUSH:
                    std::cout << "PUSH\n";
                    break;

                case Inst_type::POP:
                    std::cout << "POP\n";
                    break;

                case Inst_type::HLT:
                    std::cout << "HLT\n";
                    break;
            }
        }
        else if(token.m_type == Type::NUM) {
            std::cout << "Token type: NUM, ";
            int value = std::get<int>(token.m_value);
            std::cout << value << '\n';
        }
    }

    //parse

    return 0;
}
