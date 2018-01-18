#include <iostream>
#include <vector>

using namespace std;

/* def */
/* var */
int rsize=0, csize=0;
vector < int* > matrix;
vector < int* > accumweight;

/* func */
void input_read();
void find_path();
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
}
