#include <iostream>
#include <cstdio>
using namespace std;

/*
    * 문제 : 1부터 N까지 임의로 뒤집을 때 나오는 문자열
    * 조건
      - 뒤집는 것은 1~N까지를 반전시키는 것을 의미
      - 뒤집는 것은 선택 가능하다.
    * 출력 : 가장 순서상 제일 앞에 오는 문자열을 구해라
*/
//ABC에 대하여 오류남.
int main()
{
    char _in[10000];
    scanf("%s", _in);
    /*
      BCDAF -> 제일 빠른 녀석을 최대한 뒤로 밀어넣는다. 그리고 마지막에 뒤집으면 반전
      (1) 현재 문자열에서 '제일 뒤에' + '최소 알파벳' 찾고
      (2) 그 때 지점이 K 라고 할 때,
      (3.1) K가 전체 길이 반보다 뒤에 있다면, 현재 문자열 = 현재문자열.substr(1, K)
      (3.1) 반보다 앞에 있다면, "역전"
    */
    int _num = 10000, max_idx = 10000, init = 10000;
    int count = 0;
    while (_num > 1) {
        //최소 지점 찾기
        int min_val = 26;
        for (int i = 0; i < _num; ++i) {
            if (_in[i] == '\0') { _num = i; init = max_idx; break;}//전체길이 확인
            if (_in[i]-'A' <= min_val) {//앞단에 서는 알파벳 찾기
                min_val = (int)_in[i]-'A';
                max_idx = i;//제일 뒷값을 저장
            }
        }
        //예외 처리 : 이미 정답에 도달한 상태 체크
        if (init == 0) {break;}
        else if (init == 1) { _num = init + 1;}
        //절반확인
        if (_num/2 <= max_idx) {
            _num = max_idx; //현재 문자열 = 현재문자열.substr(1, K-1);
        } else {
            // cout << ">>flip" << endl;
            //뒤집기
            for (int i = 0; i < _num/2; ++i) {
                char c = _in[_num-i-1];//끝열
                _in[_num-i-1] = _in[i];//첫열
                _in[i] = c;
            }
            _num -= (max_idx+1);
        }
    }
    //출력
    for (int i = init; i >=0; --i) cout << _in[i];
    for (int i = init+1; _in[i] != '\0'; ++i) cout << _in[i];
    return 0;
}
