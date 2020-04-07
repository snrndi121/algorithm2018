#include <iostream>

using namespace std;

/*
영어 대소문자와 띄어쓰기만으로 이루어진 문자열이 주어진다.
이 문자열에는 몇 개의 단어가 있을까?

주의 사항
(1) 단, 한 단어가 여러 번 등장하면 등장한 횟수만큼 모두 세어야 한다.
(2) 또한 문자열의 앞과 뒤에는 공백이 있을 수도 있다.
(3) 단어는 띄어쓰기 한 개로 구분되며, 공백이 연속해서 나오는 경우는 없다.

입력
첫 줄에 영어 대소문자와 띄어쓰기로 이루어진 문자열이 주어진다.
이 문자열의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 단어의 개수를 출력한다.
*/
/*
  * 문제 = "특정 문자 찾기"
  * 특이점 = "getline 사용"
*/
string read_input()
{
  string _in;
  getline(cin, _in);
  return _in;
}
int solve(string _arg)
{
  /* coutn null */
  int res = 0;
  const int exception[2] = {0, _arg.size() - 1};
  for (int begin = 0; begin < _arg.size(); ++begin) {
      if (_arg[begin] == ' '
      && begin != exception[0]
      && begin != exception[1]) { res++;}
  }
  return res + 1;
}
void write_output(int _arg)
{
  cout << _arg;
}
int main() {
  string _in = read_input();
  int _res = solve(_in);
  write_output(_res);
  return 0;
}
