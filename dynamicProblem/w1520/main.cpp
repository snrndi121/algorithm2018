#include <iostream>
#include <vector>

using namespace std;

/* def */
/* var */
vector < int* > matrix;
vector < int* > accumweight;

/* func */
void input_read();
void find_path();
bool biggerThan(int row, int col, char* target);
bool checkRight(int row, int col);

int main()
{
    input_read();
    find_path();

    return 0;
}
void input_read()
{
    int r,c;
    cin >> r >> c;
    while(r-- > 0)
    {
        int* col = new int[c];
        for(int i=0; i<c; ++i)
        {
            cin >> col[i];
        }
        matrix.push_back(col);
    }
}
void find_path()
{
    unsigned rowSize=matrix[0].size(), colSize=matrx[0][0].size();
    for(unsigend row=0; row < matrix.size(); ++row)
    {
          int* c = new int[rowSize];
          for(unsigned col=0; col < colSize; ++col)
          {
              //part1. checkLeftnUp
              if(biggerThan(row, col, new char("left")) && biggerThan(row, col, new char("right"))
              {
                  if(checkRight(row, col) == true)
                  {
                      c[col]++;
                  }
                  if(row != 0) { c[col] += accumweight[col-1][col];}
              }
              else {
                  c[col] = 0;
              }
          }
          accumweight[row].push_back(c);
    }
}
bool checkRight(int row, int col)
{
    int csize=matrix[0][0].size();
    if(col != csize - 1)
    {
        return matrix[row][col+1] < matrix[row][col];
    }
    return false;
}
bool biggerThan(int row, int col, char* target)
{
    if(target == "left")
    {
        if(col != 0) {
            return (matrix[row][col-1] < matrix[row][col]);
        }
    }
    else {
      if(row != 0) {
          return matrix[row-1][col-1] < matrix[row][col];
      }
    }
    return false;
}
