#include <iostream>

using namespace std;

/*
  * 다이얼 문제 : 숫자 1이 금속판까지 거리가 2초, 숫자 2는 3초...숫자9...숫자0
  * 할머니는 영문 스트링으로 해당 숫자를 매칭한다.
  * {숫자 2 : ABC, 숫자 3 : DEF, 숫자 4 : GHI, ... , 숫자 9 : WXYZ}
  * 영문 스트링은 2 ~ 15자리
  * 숫자 0과 1은 배정된 영문이 없으니 일단 제외하고 문제 풀기
  * 이 때 다이얼을 돌리는 데 걸린 총 시간을 구해라
*/
// UNUCIC
// 646020
// 868242
int main()
{
    string _input;
    cin >> _input;

    const int dial_time[26] = {
        2, 2, 2,//0 : ABC
        3, 3, 3,//1 : DEF
        4, 4, 4,//2 : GHI
        5, 5, 5,//3 : JKL
        6, 6, 6,//4 : MNO
        7, 7, 7, 7,//5 : PQRS
        8, 8, 8,//6 : TUV
        9, 9, 9, 9//7 : WXYZ
    };
    int res = 0;
    for (int i = 0 ; i < _input.size(); ++i) {
        res += (dial_time[_input[i] - 'A']) + 1;
    }
    cout << res << endl;
    return 0;
}
