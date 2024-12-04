#include <iostream>
#include <numeric>
#include "File.h"

const std::string VALID_SIGNATURE{ "mul(,)" };

/// <summary>
/// Compares the given char with an appropriate part of mul.signature
/// </summary>
/// <param name="c">The char to compare with mul.signature</param>
bool compare_with_valid_mul(char c, int& first_int, int& second_int)
{
	static int comparison_progress{ 0 };
	static std::string full_integer{};

	if (c == VALID_SIGNATURE[comparison_progress])
	{
		comparison_progress++;

		if (c == ',')
		{
			first_int = std::stoi(full_integer);
			full_integer = "";
		}
		else if (c == ')')
		{
			second_int = std::stoi(full_integer);
			full_integer = "";
			comparison_progress = 0; // we're at the end, so reset progress
		}

		return true; // this char is valid
	}
	else if ((VALID_SIGNATURE[comparison_progress] == ',' || VALID_SIGNATURE[comparison_progress] == ')') 
			&& std::isdigit(c)) // should capture a number
	{
		full_integer.push_back(c);
		return true; // this char is valid
	}
	else
	{
		comparison_progress = 0; // reset progress
		full_integer = ""; // reset integer since mul isn't valid
		return false; // char is not valid
	}
}

int main()
{
	std::string file_path{ "../input.txt" };
	File input_file{};
	input_file.open_file(&file_path);

	std::vector<char> all_chars{ input_file.read_file_char_by_char() };
	std::string valid_mul{};
	std::vector<std::string> valid_muls{};
	std::vector<int> mul_results{};


	int first_num{ 0 };
	int second_num{ 0 };

	for (auto& const c : all_chars)
	{
		if (compare_with_valid_mul(c, first_num, second_num))
		{
			valid_mul.push_back(c);
		}
		else
		{
			valid_mul = "";
		}

		if (c == ')' && valid_mul.length() > 2) // 2 is completely arbitrary
		{
			mul_results.push_back(first_num * second_num);
			valid_mul = "";
		}
	}

	int sum_results = std::accumulate(mul_results.begin(), mul_results.end(), 0);
	std::cout << sum_results << std::endl;

	return 0;
}