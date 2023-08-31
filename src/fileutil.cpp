#include <fstream>
//#include <sstream>
#include <string>
#include <iostream>

#include "../include/fileutil.hpp"

std::string get_file_contents(const char* path) {
    if(!path) {
        std::cerr << "Failed getting file's path\n";
        exit(EXIT_FAILURE);
    }

    std::fstream file(path, std::ios::in);
    
    if(!file.is_open()) {
        std::cerr << "Failed to open file\n";
        exit(EXIT_FAILURE);
    }

    file.seekg(0, std::ios::end);
    size_t size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::string contents(size, '\0');
    if(!file.read(&contents[0], size)) {
        throw std::runtime_error("Failed to read file!\n");
    }

    /*
    std::stringstream content_stream;
    content_stream << file.rdbuf();

    std::string contents = content_stream.str();
    */
    return contents;
}
