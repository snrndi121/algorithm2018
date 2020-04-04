#include <iostream>
#include <algorithm>
using namespace std;

/*
  * 기본 개념 : 최소값 찾는 문제였음
  * 풀이 : wait_time 배열 sort해서 wait[0]에 매번 들어온 사람*1분 = 처리 시간 삽입하면 됨
  * 최종 : 최종 결과값은 wait_time - sort()해서 마지막 값 출력함
*/
//var
int N, K;
int *group, *wait_time;
int res = 0;

void read_input()
{
    cin >> N >> K;
    group = new int[N];
    wait_time = new int[K];
    for (int i = 0; i < N; ++i) {cin >> group[i];}
}
void write_output()
{
    cout << "\n res :" << res << endl;
}

void printWaitList(int *src, int _size)
{
    for (int i = 0 ; i < _size; ++i)
      cout << src[i] << ' ';
    cout << endl;
}
int solve()
{
    printWaitList(wait_time, K);
    wait_time[0] = group[0];
    for (int i = 1; i < N; ++i) {
        //wait_time 중 최소인 값
        sort(wait_time, wait_time + K);
        printWaitList(wait_time, K);
        //해당 wait_time += group[i]
        wait_time[0] += group[i];
        //전체적으로 - 1? 그런데 이게 의미가 있을지는 모르겠지만, 충실히 구현한다면
    }
    printWaitList(wait_time, K);
    sort(wait_time, wait_time + K);
    res = wait_time[K - 1];
}
int main()
{
    read_input();
    solve();
    write_output();
    return 0;
}
