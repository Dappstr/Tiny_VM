#include <cstring>
#include <functional>
#include <iostream>
#include <vector>

#include "../include/fileutil.hpp"
#include "../include/lexer.hpp"
#include "../include/tokenizer.hpp"
#include "../include/parser.hpp"

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
    
    //parse
    std::vector<int> stack;
    parse(tokens, stack);

    return 0;
}
