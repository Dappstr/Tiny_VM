#pragma once

#include <string>
#include <vector>
#include <variant>

enum Type {
    NUM,
    INST
};

enum Inst_type {
    ADD,
    SUB,
    MUL,
    PUSH,
    POP,
    HLT
};

struct Token {
    Type m_type;
    std::variant<int, Inst_type> m_value;
};

std::vector<Token> tokenize(const std::vector<std::string>& lexemes);
