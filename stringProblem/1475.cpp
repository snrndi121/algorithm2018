#include <iostream>
#include <cmath>
using namespace std;

/*
  * 풀이
(*) 숫자 한 세트 [0 ~ 9]
로직 (1) : 6과9의 개수 N 개라면 = 최소 ceil(n/2) 개 필요
로직 (2) : 나머지 자리 수의 개수 = K개라면 최소 K개 필요
결과 : (1)과 (2)의 최대값
*/
int main()
{
    int visitCNT[10];
    fill_n(visitCNT, 10, 0);
    string _input;cin >> _input;
    //출현한 숫자세트
    for (int i = 0; i < _input.size(); ++i) {visitCNT[_input[i] - '0']++;}
    //로직(1)
    int max69 = ceil((float)(visitCNT[6]+visitCNT[9])/2), res = 0;
    visitCNT[6] = 0;visitCNT[9] = 0;
    //로직(2)
    for (int i = 0; i < 10; ++i) { res = max(res, visitCNT[i]);}
    //결과
    cout << max(max69, res) << endl;
    return 0;
}
