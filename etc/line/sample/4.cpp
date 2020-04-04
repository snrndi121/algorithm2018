#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
  * 개념 : 복잡한 알고리즘은 X
  * 풀이 : 0(빈 공간)이 제일 많은 구간 찾아서, 다음에 올 곳이 어딘지만 찾으면 됨
  * 결론 : 부분 실행됨. 양끝점 처리 방법이 구질구질해짐
*/
//def
//var
int N = 0;
vector < bool > seated;
//func
void read_input()
{
    cin >> N;
    seated.push_back(1);
    for (int i = 0; i < N; ++i) {bool e; cin >> e; seated.push_back(e);}
    seated.push_back(1);
}
void write_output()
{

}
bool cmp(const pair <int, int> &a, const pair <int, int> &b)
{
    return a.second <= b.second;
}

//1 0 0 1 0 0 0 0 0 0
void setVacancy(vector < pair < int, int > >& src)
{
    int zero_start = N, zero_count = 0;
    //processing -> zero
    for (int i = 1 ; i < N + 2; ++i) {
        if (!seated[i]) {
            zero_start = min(zero_start, i);
            zero_count++;
        } else {
            if (zero_count > 0) {
              src.push_back(make_pair(zero_start, zero_count));
              zero_start = N; zero_count = 0;
            }
        }
    }
}
void solve()
{
    vector < pair < int, int > > zero_distance;
    setVacancy(zero_distance);
    //
    int res = 0;
    sort(zero_distance.begin(), zero_distance.end(), cmp);
    //get index
    pair < int, int > target = zero_distance[zero_distance.size() - 1];
    for (int i = 0; i < zero_distance.size(); ++i)
    {
        cout << zero_distance[i].first << ", " << zero_distance[i].second << endl;
    }
    //check vacancy
    //한쪽이 비어 있는 경우
    if (target.first == 0
      || target.first + target.second == N) {
      cout << "#1" << endl;
      res = target.second - 1;
    }
    //양쪽이 다 차있는 경우
    else {
      cout << "#2" << endl;
      // int left = target.first,
      //   right = left + target.second;
      // res = (left + right)/2;
      res = (target.second/2);
    }
    cout << " # largest zero_start : " << target.first << endl;
    cout << " # its count :" <<  target.second << endl;
    cout << " # result :" << res << endl;
}
int main()
{
    read_input();
    solve();
    write_output();
    return 0;
}
