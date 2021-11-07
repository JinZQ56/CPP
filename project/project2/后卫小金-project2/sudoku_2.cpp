#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <utility>
#include <bitset>

// initialize solution number
int ans = 0;

// initialize the flag arrays
std::vector<std::bitset<9>> row;
std::vector<std::bitset<9>> col;
std::vector<std::vector<std::bitset<9>>> block;


void print_sudoku(std::vector<std::vector<int>> sudoku)
{
	// print sudoku
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			std::cout << sudoku[i][j] << ' ';
			// std::cout << s[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void read_sudoku(std::vector<std::vector<int>>& sudoku, std::string& txt)
{
	std::string path = "..\\sudoku_data\\" + txt;
	// std::vector<std::vector<int>> sudoku(9, std::vector<int>(9));
	// int s[9][9];

	// open file
	std::ifstream file(path);

	//read sudoku
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			file >> sudoku[i][j];
			// file >> s[i][j];
		}
	}

	// close file
	file.close();

	// print sudoku
	// print_sudoku(sudoku);
}

std::bitset<9> poss_stat(int i, int j)
{
	return ~(row[i] | col[j] | block[i / 3][j / 3]);
}

std::vector<int> next(std::vector<std::vector<int>>& sudoku)
{
	std::vector<int> pos;
	int min_cnt = 10;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (sudoku[i][j] != 0) continue;
			auto pos_cnt = poss_stat(i, j);
			if (pos_cnt.count() >= min_cnt) continue;
			pos = { i,j };
			min_cnt = pos_cnt.count();
		}
	}
	return pos;
}

void flip(int i, int j, int d, bool flag)
{
	row[i][d] = (flag) ? 1 : 0;
	col[j][d] = (flag) ? 1 : 0;
	block[i / 3][j / 3][d] = (flag) ? 1 : 0;
}

void dfs(std::vector<std::vector<int>>& sudoku, int cnt)
{
	if (cnt == 0)
	{
		ans = ans + 1;
		return;
	}

	auto pos = next(sudoku);
	int i = pos[0];
	int j = pos[1];

	auto bits = poss_stat(i, j);

	// for (int digit = 0; digit < 9 && !valid ; ++digit)
	for (int digit = 0; digit < 9; ++digit)
	{
		if (!bits.test(digit)) continue;
		flip(i, j, digit, true);
		sudoku[i][j] = digit + 1;
		dfs(sudoku, cnt - 1);
		sudoku[i][j] = 0;
		flip(i, j, digit, false);
	}
}

void solve_sudoku(std::vector<std::vector<int>>& sudoku)
{
	// set false to flag arrays
	row = std::vector<std::bitset<9>>(9, std::bitset<9>());
	col = std::vector<std::bitset<9>>(9, std::bitset<9>());
	block = std::vector<std::vector<std::bitset<9>>>(3, std::vector<std::bitset<9>>(3, std::bitset<9>()));

	// set falg arrays according to sudoku
	int cnt = 0;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (sudoku[i][j] == 0)
			{
				++cnt;
				continue;
			}
			else
			{
				int digit = sudoku[i][j] - 1;
				flip(i, j, digit, true);
			}
		}
	}

	// backtracking
	dfs(sudoku, cnt);
}

int main() {
	/* read file */
	std::string txt = "hard++.txt";
	std::vector<std::vector<int>> sudoku(9, std::vector<int>(9));
	read_sudoku(sudoku, txt);

	/* start */
	std::chrono::time_point<std::chrono::system_clock> server_create_time_ = std::chrono::system_clock::now();

	/* solve problem */
	solve_sudoku(sudoku);
	//print_sudoku(sudoku);

	/* end */
	std::cout << "solution_count = " << ans << std::endl;
	auto current_time = std::chrono::system_clock::now();
	std::chrono::duration<double, std::milli> duration_mili = current_time - server_create_time_;
	std::cout << "PrintDuration : duration_mili duration = " << (long)duration_mili.count() << " ms" << std::endl;

	/* print */
	// print result when there is only one solution
	if (ans == 1)
	{
		std::cout << "the only solution is: " << std::endl;
		print_sudoku(sudoku);
	}

}