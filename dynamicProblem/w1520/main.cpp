#include <iostream>
#include <vector>

using namespace std;

/* def */
/* var */
unsigned rsize = 0, csize = 0;
vector < int* > matrix;
vector < int* > accumweight;

/* func */
void input_read();
void find_path();
bool biggerThan(int row, int col, const char* target);
bool checkRight(int row, int col);
void print_accum();

int main()
{
	input_read();
	find_path();

	print_accum();
	return 0;
}
void input_read()
{
	cin >> rsize >> csize;
	int i = 0;
	while (i++ < rsize)
	{
		int* col = new int[csize];
		for (int i = 0; i<csize; ++i)
		{
			cin >> col[i];
		}
		matrix.push_back(col);
	}
}
void find_path()
{
	cout << "\n --- find Path --- " << endl;
	for (unsigned row = 0; row < matrix.size(); ++row)
	{
		int* c = new int[rsize];
		for (unsigned col = 0; col < csize; ++col)
		{
			cout << matrix[row][col] << ':';
			c[col] = 0;
			//part1. checkLeftnUp
			if (!biggerThan(row, col, "left"))
			{
				cout << "->(1)";
				//part2. Is it possible to go right
				if (checkRight(row, col) == true)
				{
					cout << "->(2)";
					c[col] = 1;
				}
			}
			else {
				cout << "->(0)";
			}
			//part3. Inheritance from top.
			if (row != 0 && !biggerThan(row, col, "up"))
			{
				c[col] += accumweight[row - 1][col]; cout << "->(3)";
			}
			cout << endl;
		}
		accumweight.push_back(c);
	}
}
bool checkRight(int row, int col)
{
	if (col != csize - 1)
	{
		return matrix[row][col+1] < matrix[row][col];
	}
	return false;
}
bool biggerThan(int row, int col, const char* target)
{
	cout << "compare :" << (target == "left") << endl;
	if (target == "left")
	{
		if (col != 0) {
			return (matrix[row][col - 1] <= matrix[row][col]);
		}
	}
	else if(target == "up")
	{
		if (row != 0) {
			return matrix[row - 1][col - 1] < matrix[row][col];
		}
	}
	cout << "->fail";
	return true;
}
void print_accum()
{
	vector < int* >::iterator it = accumweight.begin();
	vector < int* >::iterator it_end = accumweight.end();

	for (; it != it_end; ++it)
	{
		for (int j = 0; j < csize; ++j)
		{
			cout << (*it)[j] << ' ';
		}
		cout << endl;
	}
}
