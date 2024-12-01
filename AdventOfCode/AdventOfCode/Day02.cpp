#include <iostream>
#include <string>
#include "File.h"

int main()
{
	std::string filePath{ "../input.txt " };
	File inputFile{};
	inputFile.open_file(&filePath);

	std::vector<std::string> lines;
	lines = inputFile.read_lines_from_file();

	inputFile.display_all_lines(lines);

	std::cout << "Hello World" << std::endl;
	return 0;
}