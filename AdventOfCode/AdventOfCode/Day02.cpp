#include <iostream>
#include <string>
#include "File.h"

std::vector<int> read_numbers_from_line(const std::string& line)
{
	std::vector<int> numbers_from_line{};
	std::string numbers{};
	for (int i = 0; i < line.size(); ++i)
	{
		if (line[i] == ' ')
		{
			numbers_from_line.push_back(std::stoi(numbers));
			numbers = "";
		}
		else
		{
			numbers.push_back(line[i]);
		}

		// catch the last digit
		if (i + 1 == line.size() - 1)
		{
			numbers.push_back(line[i + 1]);
			numbers_from_line.push_back(std::stoi(numbers));
			numbers = "";
		}
	}

	return numbers_from_line;
}

bool determine_is_increasing(const std::vector<int>& line)
{
	if (line[0] < line[1])
	{
		return true;
	}
	else if (line[0] > line[1])
	{
		return false;
	}
}

// unchanged from part 1
int compare_values(const std::vector<int>& numbers, const bool& is_increasing)
{
	for (int i = 0; i < numbers.size() - 1; ++i)
	{
		if ((std::abs(numbers[i] - numbers[i + 1]) > 3)				// difference is more than 3
			|| (numbers[i] == numbers[i + 1])						// numbers are equal
			|| (is_increasing && numbers[i] > numbers[i + 1])		// numbers are no longer increasing
			|| (!is_increasing && numbers[i] < numbers[i + 1]))		// numbers are no longer decreasing
		{
			return 0;
		}
	}

	return 1;
}

// added for part 2
int dampener(std::vector<int> numbers, bool& is_increasing)
{
	int number_cache{0};
	int safety_index{0};
	for (int i = 0; i < numbers.size(); ++i)
	{
		number_cache = numbers[i];
		numbers.erase(numbers.begin() + i);
		is_increasing = determine_is_increasing(numbers); // https://www.reddit.com/r/adventofcode/comments/1h4shdu/2024_day_2_part2_edge_case_finder/ identified this missing line
		safety_index = compare_values(numbers, is_increasing);

		// return as soon as the data is safe
		if (safety_index == 1)
		{
			return 1;
		}

		// put the number you cached back at the index you removed it from
		numbers.insert(numbers.begin() + i, number_cache);
	}
	return 0;
}

int day02_solution()
{
	std::string filePath{ "../input.txt " };
	File inputFile{};
	inputFile.open_file(&filePath);

	std::vector<std::string> lines;
	lines = inputFile.read_lines_from_file();

	int number_of_safe_reports{ 0 };

	for (auto& const line : lines)
	{
		std::vector<int> line_numbers = read_numbers_from_line(line);
		bool is_increasing{ determine_is_increasing(line_numbers) };
		
		// number_of_safe_reports += compare_values(line_numbers, is_increasing); // cout number_of_safe_reports for part 1 solution

		int safety_index{ compare_values(line_numbers, is_increasing) };

		if (safety_index == 0)
		{
			safety_index += dampener(line_numbers, is_increasing);
		}

		number_of_safe_reports += safety_index;
		std::cout << number_of_safe_reports << std::endl;
	}

	std::cout << number_of_safe_reports << std::endl;

	//inputFile.display_all_lines(lines); // make sure the input is correct

	return 0;
}