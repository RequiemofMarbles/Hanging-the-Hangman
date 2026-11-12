#pragma once

#include <string>
#include <vector>

std::vector<std::string> getAllDictionaryWords(const std::string& filename);
std::string pickRandomWord(const std::vector<std::string>& words);
