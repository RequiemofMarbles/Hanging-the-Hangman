#include <iostream>
#include <string>

#include "hangman.h"

int main()
{
	const std::string wordListFile = "popular.txt";
	const std::vector<std::string> words = getAllDictionaryWords(wordListFile);

	if (words.empty())
	{
		std::cerr << "No words were loaded. Make sure popular.txt is in the program's working directory."
			<< std::endl;
		return 1;
	}

	std::cout << "Loaded " << words.size() << " words." << std::endl;
	std::cout << "Random word: " << pickRandomWord(words) << std::endl;
	return 0;
}
