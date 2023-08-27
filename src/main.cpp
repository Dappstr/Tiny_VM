#include <cstdlib>
#include <cstring>
#include <iostream>
#include "../include/fileutil.hpp"

int main(int argc, char* argv[]) {
    
    if(argc < 2) {
        std::cerr << "USAGE: " << argv[0] << " <path_to_file>\n";
        exit(EXIT_FAILURE);
    }

    //get file contents
    char* path = argv[1];
    std::string contents = get_file_contents(path);

    std::cout << contents;
    //lex
    
    //tokenize

    //parse

    return 0;
}
