#pragma once

#include "tokenizer.hpp"
#include <vector>

void parse(const std::vector<Token>& tokens, std::vector<int>& stack);
