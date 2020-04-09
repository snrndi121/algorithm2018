#include <iostream>

using namespace std;

int main()
{
    string _input;
    cin >> _input;

    int cnt[26];
    fill_n(cnt, 26, 0);
    /* 다른 사람은 % 32 라는 방식으로 대소문자를 변환해줬음 */
    const char alpha_a[2] = {'a', 'A'};

    //count existance
    for (int i = 0; i < _input.size(); ++i) {
        //소문자 - 소문자 = 0 ~ 25 사이 값 > 0
        //대문자 - 소문자 < 0
        int loc = _input[i] - alpha_a[0];
        if (loc >= 0) { cnt[loc]++;}//소문자면
        else {//대문자면
            loc = _input[i] - alpha_a[1];//대문자-대문자 = 0 ~ 25 사이 값
            cnt[loc]++;
        }
    }
    //judegement
    /* 사실 이 판단 부분은 두 가지로 변환 가능함
      * part1. cnt 에서 최대 카운트 가지는 max_index 찾기
      * part2. cnt 에서 max_index도 아니면서 cnt[max_index] == cnt[i] 인 i 찾으면 됨
      *         그 여부가 boolean이라면 true 처리 해서 마지막에 print 부분에 찍어내면 됨
    */
    //max_prev_idx : 같은 max 값을 가지는 알파벳 위치
    //max_idx : max 값을 가지는 알파벳 위치
    int max_prev_idx = -1, max_idx = 0;
    for (int i = max_idx; i < 26; ++i) {
        if (cnt[max_idx] < cnt[i]) {
            max_idx = max_prev_idx = i;//새로운 최대값 등장하면 둘 다 i로 초기화
        }
        else if (cnt[max_idx] == cnt[i]) {//동일한 알파벳 나온다면
            max_prev_idx = max_idx;//앞 녀석은 max_prev_idx,
            max_idx = i;//뒷 녀석은 max_idx에 할당
        }
    }
    //print
    /*
      * max_prev_idx != max_idx : 같은 max 값을 가지는 녀석이 둘 이상이라면
    */
    if (max_prev_idx != max_idx) {cout << "?";}
    else { cout << (char)(alpha_a[1] + max_idx);}
    return 0;
}
