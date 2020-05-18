#include <iostream>
using namespace std;

/*
  * 문제 : 0과 1로 이뤄진 문자열에서 전부 0과 1를 바꾸는 상황
  * 조건
    - 0이나 1 둘중 하나로만 이뤄진 문자열로 변환
    - 뒤집기 연산도 0 또는 1 둘 중 하나로 수행됨
    - 문자열 길이는 100만이 최대
  * 출력 : 뒤집은 횟수 출력
*/
int main()
{
    string _input;
    getline(cin, _input);
    //
    char inver_last = _input[_input.size()] == '0'? '1' : '0';
    _input.push_back(inver_last);
    //
    int cnt0to1 = 0, cnt1to0 = 0;
    bool isDup = false;
    for (int i=0; i != _input.size()-1; ++i) {
        //달라진 구간 체크
        if (!isDup)
          if (_input[i] == '0') cnt0to1++;
          else cnt1to0++;
        //앞뒤 연속성 체크
        if (_input[i] == _input[i+1]) isDup = true;
        else isDup = false;
    }
    int answer = cnt0to1 > cnt1to0? cnt1to0 : cnt0to1;
    cout << answer << endl;
    return 0;
}
//다른 사람 풀이
//인접한 문자열이 바뀐 횟수/2, 이 답
/*
int main(){
	int prev = -1, cur, cnt = 1;
	while(scanf("%1d", &cur) > 0){
		if(prev != -1 && prev != cur) cnt++;
		prev = cur;
	}
	printf("%d\n", cnt/2);
}
*/
