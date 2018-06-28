#include <iostream>
#include <vector>

using namespace std;

/* def */
/* var */
<<<<<<< HEAD
unsigned rsize = 0, csize = 0;
=======
int rsize=0, csize=0;
>>>>>>> efb5bd87f0f9af3bc3ba9e8adcc1def90840d0c9
vector < int* > matrix;
vector < int* > accumweight;

/* func */
void input_read();
void find_path();
<<<<<<< HEAD
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
=======
void accum_print();
bool lowerThan(int row, int col, const char* target);

int main()
{
    input_read();
    find_path();
    accum_print();

    return 0;
}
void input_read()
{
    int index=0;
    cin >> rsize >> csize;
    while(index++ < rsize)
    {
        int* c= new int[csize];
        for(int col=0; col < csize; ++col)
        {
            cin >> c[col];
        }
        matrix.push_back(c);
    }
}
void find_path()
{
    for(unsigend r=0; r < rsize; ++r)
    {
        int* col = new int[csize];
        for(unsigned c=0; c < csize; ++c)
        {
            col[c] = 0;
            cout << matrix[row][col] << ':';
            if(lowerthan(r, c, "left"))
        }
    }
}
bool lowerThan(int row, int col, const char* target)
{
    swithch(target)
    {
        case "left" :
          if(col != 0)
            return (matrix[row][col] < matrix[row][col-1]);
          else if(col != csize-1)
            return maxtrix[row][col] < matrix[row][col+1];
          else
            return false;
        case "right" :
          if(col != csize-1)
            return matrix[row][col] < matrix[row][col+1];
          else return false;
        case "up" :
          if(row != 0)
            return matrix[row][col] < matrix[row-1][col];
          return false;
        default :
          cout << "->fail";
          return false;
    }
}
void accum_print()
{
    vector < int* >::iterator it=accumweight.begin();
    vector < int* >::iterator it_end=accumweight.end();
    for(; it != it_end; ++it)
    {
        for(int j=0; j<csize; ++j)
        {
            cout << (*it)[j] << ' ';
        }
        cout << endl;
    }
>>>>>>> efb5bd87f0f9af3bc3ba9e8adcc1def90840d0c9
}
