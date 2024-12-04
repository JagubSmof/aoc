#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

class File
{
public:
	~File();
	void open_file(std::string* filePath);
	std::vector<std::string> read_lines_from_file();
	std::vector<char> read_file_char_by_char();
	void display_all_lines(std::vector<std::string>& const linesFromFile); // mostly to make sure I'm reading it correctly

private:
	void close_file();
	std::string line;
	std::vector<std::string> lines;
	std::ifstream inputFile;
};

