#include <iostream>
#include <cstdio>
using namespace std;

/*
  문제 : 동전이 모두 앞면(0)이 나오도록 뒤집어라
  조건
    - 한 번 (a, b)를 뒤집으면 (0,0) ~ (a,b) 영역 모두 뒤집힌다
    - 뒤집은 횟수는 선택된 (a,b)수와 같다.
  출력 : 뒤집은 횟수를 구해라.

*/
int main()
{
    int N, M; scanf("%d %d ", &N, &M);
    char* _input = new char[N*M];
    for (int i=0; i < N; ++i) {
        char *str = new char[M];
        scanf("%s", str);
        for (int j=0; j < M; ++j) {_input[i*M + j] = str[j];}
    }
    //
    /*
      제일 외곽부터 처리 : row가 클수록, col이 클수록
      00    11    00    10    00
      01 -> 10 -> 10  ->00  ->00
      0001 1110 0010 1000 0000

    */
    int answer = 0;
    for (int col = M-1; col >= 0; --col) {
        for (int row = N-1; row >= 0; --row) {
            int last = M*row + col;
            // cout << "> cur :" << last << endl;
            if (_input[last] == '1') {
                // cout << "#find : (" << row << ", " << col << ")" << endl;
                _input[last] = '2';//일종의 삭제 연산
                answer++;
                //뒤집기 연산
                for (int i = 0; i < last; ++i) {
                    if (_input[i] != '2') {//삭제된 것이 아니라면
                        _input[i] = _input[i] == '0'? '1' : _input[i] == '1'? '0' : '2';//뒤집기
                    }
                }
            }
        }
    }
    // cout << " > a :" << answer << endl;
    cout << answer << endl;
    return 0;
}
