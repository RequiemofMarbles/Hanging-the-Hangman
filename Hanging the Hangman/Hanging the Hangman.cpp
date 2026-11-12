#include "hangman.h"

#include <fstream>
#include <iostream>
#include <random>

std::vector<std::string> getAllDictionaryWords(const std::string& filename)
{
	std::ifstream fin(filename);
	if (!fin)
	{
		std::cerr << "Could not open the word list: " << filename << std::endl;
		return {};
	}

	std::vector<std::string> words;
	std::string currentWord;
	while (std::getline(fin, currentWord))
	{
		if (!currentWord.empty() && currentWord.back() == '\r')
		{
			currentWord.pop_back();
		}

		if (!currentWord.empty())
		{
			words.push_back(currentWord);
		}
	}

	return words;
}

std::string pickRandomWord(const std::vector<std::string>& words)
{
	if (words.empty())
	{
		return {};
	}

	static std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<std::size_t> distribution(0, words.size() - 1);
	return words[distribution(rng)];
}