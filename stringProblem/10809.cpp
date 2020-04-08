#include <iostream>
#include <map>
using namespace std;

/*
  1. 소문자만으로 이뤄진 문장 S가 주어지고 최대 길이는 100
  2. 26개의 결과를 출력할 것
  3. a~z의 알파벳에 대하여 처음 찾은 위치를, S를 구성한 알파벳이 아니면 -1을 출력

  풀이 : 아스키값으로 인덱스 위치를 찾아내는 방법이 중요했음
*/
int main()
{
    string _input;
    cin >> _input;

    int res[26];
    fill_n(res, 26, -1);

    for (int i = 0; i < _input.size(); ++i) {
        int loc = _input[i] - 'a';//key-point
        if (res[loc] == -1) { res[loc] = i;}
    }
    //print
    for (int i = 0; i < 26; ++i) cout << res[i] << ' ';
    return 0;
}
