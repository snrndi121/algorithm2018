#include <iostream>

using namespace std;

/*
주의 사항
(1) 단, 한 단어가 여러 번 등장하면 등장한 횟수만큼 모두 세어야 한다.
(2) 또한 문자열의 앞과 뒤에는 공백이 있을 수도 있다.
(3) 단어는 띄어쓰기 한 개로 구분되며, 공백이 연속해서 나오는 경우는 없다.
*/
/*
  * case1 : 공백
  * case2 : 공백 + {단어 N}
  * case3 : 공백 + {단어 N} + 공백
  * case4 : {단어 N}
*/
/*
  * 처음부터 양끝에 공백이 있다고 생각.
  * _arg[0], _arg[size - 1]이 공백이면 세지 않음.
  * 로직 (1) : case4 경우만 고려, 나머지는 예외처리
*/
int main()
{
  char _arg[1000001];cin.getline(_arg, 1000001);
  //로직 (1) : case4 처리
  int i = 0, res = 0;
  for (i = 0; _arg[i] != '\0'; ++i)
      if (_arg[i] == ' ') {res++;}
  //예외처리 : case1, 2, 3
  if (_arg[0] == ' ') {res--;}
  if (_arg[i - 1] == ' ') {res--;}
  //
  cout << res + 1;
  return 0;
}
