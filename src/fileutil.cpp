#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

#include "../include/fileutil.hpp"

std::string get_file_contents(const char* path) {
    std::fstream file(path, std::ios::in);
    if(!file.is_open()) {
        std::cerr << "Failed to open file\n";
        exit(EXIT_FAILURE);
    }

    std::stringstream content_stream;
    content_stream << file.rdbuf();

    std::string contents = content_stream.str();
    return contents;
}
