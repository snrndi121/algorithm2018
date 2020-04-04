#include <iostream>
#include <vector>

using namespace std;

/*
  숫자의 패턴
  0번 패턴 : ###
  1번 패턴 : ..#
  2번 패턴 : #..
  3번 패턴 : #.#
  4번 패턴 : ... //빈칸을 채우는 것
*/
//def
//각 숫자를 패턴으로 나타냄
//각 숫자를 만들어낼 수 있는 최소의 공간임 = 5 x 9
int numberpad[10][5] = {
  {0, 3, 3, 3, 0},
  {1, 1, 1, 1, 1},
  {0, 1, 0, 2, 0},
  {0, 1, 0 ,1, 0},
  {3, 3, 0 ,1, 1},
  {0, 2, 0 ,1, 0},
  {2, 2 ,0, 3, 0},
  {0, 1, 1, 1, 1},
  {0, 3, 0, 3, 0},
  {0, 3, 0 ,1, 1}
};
//var
vector < string > result;
vector < pair < int, string > > input;
int N;
string printStyle;
void read_input()
{
    cin >> N >> printStyle;
    int in[2];
    for (int i = 0; i < N; ++i) {
      cin >> in[0] >> in[1];
      input.push_back(make_pair(in[0], in[1]));
    }
}
void write_output()
{

}
//숫자의 세로들 중 출력해야할 세로의 영역 타입 변환
int getAreaType(int row, int curRow)
{
    int gap = maxRow - row, margin;
    if (align == 0) margin = 0;
    else if (align == 1) margin = gap/2;
    else margin = gap;

    int top = 0 + margin;
    int middle = row/2 + margin;
    int bottom = row - 1 + margin;

    if (curRow == top) return 0;
    else if (top < curRow && curRow < middle) return 1;
    else if (middle < curRow && curRow < bottom) return 3;
    else if (curRow == bottom) return 4;
    else return -1;
}
void printShape(int type, int col)//모양, 가로 길이
{
  for (int i = 0; i < col; ++i) {
      if (i == 0) { //가장 첫 열
          if(type == 1 || type == 4) cout << ".";
          else cout << "#";
      } else if (i == col - 1) {  //끝 열
          if (type == 2 || type == 4) cout << ".";
          else cout << "#";
      } else {  //나머지 중간
          if (type != 0) cout << ".";
          else cout << "#";
      }
  }
}
void printNumber(int number, int row, int col, int curRow)
{
    int areaType = getAreaType(row, curRow);//숫자의 세로줄 중 출력해야할 세로의 영역 타입 변환
    int shapeType = areaType < 0? 4 : numberPad[number][areaType];
    printShape(shapeType, col);
}
void solve()
{
    for (int row = 0; row < maxRow; ++row) {
        for (int i = 0; i < n; ++i) {
            for (int numberIdx = 0; numbers[i][numberIdx] != '\0'; numberIdx++) {
                int r = cols[i] * 2 - 1;
                int c = cols[i];
                printNumber(numbers[i][numberIdx] - '0', r, c, row);
                cout << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    read_input();
    solve();
    write_output();
    return 0;
}
