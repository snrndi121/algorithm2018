#include <iostream>

/*
  * 재귀함수 연습해봄
*/
/*
  * 세자리 수의 크기를 비교하는 문제
  * 실험자는 숫자를 거꾸로 읽는 경향이 있다
  * 숫자 두 자리는 같은 수를 주지는 않는다.
  * 0은 포함되어있지 않다.
  * 실험자가 판단하는 두 수의 비교에 대한 정답을 출력하라.
*/
using namespace std;

int bigger(const string &a, const string &b, int idx)
{
    int res = 0;
    if (idx == -1) { return 0;}//ground
    if (a[idx - 1] == b[idx - 1]) { return res + bigger(a, b, --idx);}
    return (a[idx - 1] < b[idx - 1])? -10 : 10;
}
int main()
{
    string a, b;
    cin >> a >> b;

    if (bigger(a, b, 3) > 0) cout << a[2] << a[1] << a[0];
    else cout << b[2] << b[1] << b[0];

    return 0;
}
