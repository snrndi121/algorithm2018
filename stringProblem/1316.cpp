#include <iostream>

using namespace std;
/*
  * 그룹 단어 찾기
  * 그룹 단어 : 모든 문자에 대해서 각 문자가 연속해서 나타나는 단어
  * N개의 단어 리스트가 주어지고, 그룹 단어의 수를 출력
  *
  * 한 단어 내에 문자가 나오다가 끊기면 그룹 단어가 아니다.
  * aba (x) a (o), ab(o), abc(o), bzb(x)
*/
int main()
{
    int N; cin >> N;
    string *_input = new string[N]; for (int i = 0; i < N; ++i) cin >> _input[i];

    //solution1) 발견된 마지막 위치
    //마지막으로 발견된 곳과 현재 index 거리 > 1,
    //then 그룹 문자 X
    int res = N;
    //Test case 수
    for (int i = 0; i < N; ++i) {
        cout << '-';
        short last_visit[26];//('알파벳 아스키코드', 마지막으로 발견된 곳)
        fill_n(last_visit, 26, -1);
        //각 문자열 탐색
        for (int j = 0; j < _input[i].size(); ++j) {
          int tar = _input[i][j] - 'a';
          //방문한 적 있는 문자일 경우
          if (last_visit[tar] != -1) {
              //최근 방문한 위치와 현재 위치 사이의 거리가 인접하지 않으면
              if (j - last_visit[tar] > 1) {
                  // cout << '!';
                  res--;//결과값 감소
                  break;//다음 문자열 탐색
              }
              // cout << '<';
          } else {//방문한적 없는 문자일 경우
              // cout << '~';
              // last_visit[tar] = j;//방문 위치 찍기
          }
          last_visit[tar] = j;//방문 위치 찍기
        }
        // cout << endl;
    }
    // cout << endl;
    cout << res << endl;
    return 0;
}
