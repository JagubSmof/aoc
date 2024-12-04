#include "File.h"

void File::open_file(std::string* filePath)
{
	if (!inputFile)
	{
		std::cerr << "Error: Could not open file" << std::endl;
		return;
	}
	else
	{
		inputFile.open(*filePath, std::ifstream::in);
	}
}

void File::display_all_lines(std::vector<std::string>& const linesFromFile)
{
	for (auto& const line : linesFromFile)
	{
		std::cout << line << std::endl;
	}
}

std::vector<char> File::read_file_char_by_char()
{
	std::vector<char> all_chars{};
	char current;
	while (inputFile)
	{
		inputFile >> current;
		all_chars.push_back(current);
	}

	return all_chars;
}

std::vector<std::string> File::read_lines_from_file()
{
	std::vector<std::string> file_lines{};
	while (std::getline(inputFile, line))
	{
		file_lines.push_back(line);
	}
	
	return file_lines;
}

void File::close_file()
{
	inputFile.close();
}

File::~File()
{
	close_file();
}