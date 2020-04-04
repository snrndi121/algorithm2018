#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
  * 개념 : 스케줄링
  * 풀이 : 부스가 끝나는 시점과 새로 들어온 작업의 시작 시간 비교
  * 결론 : sort 정렬시 내부 함수 유념
*/
//def
typedef pair < int, int > ptype;
typedef vector < int > vtype;
typedef vector < ptype > v_ptype;
typedef vector < vtype > v_vtype;
//var
int N = 0;
v_ptype SE;
//func
bool cmp(const ptype &a, const ptype &b)
{
    return a.first <= b.first && a.second <= b.second;
}
void read_input()
{
    cin >> N;
    for (int i = 0; i < N; ++i) {int s, e; cin >> s >> e; SE.push_back(make_pair(s,e));}
}
void write_output()
{

}
void printSE(const v_ptype& src)
{
    cout << "# print list of (s,e)" << endl;
    for (uint i = 0; i < src.size(); ++i) {
        cout << src[i].first << ", " << src[i].second << endl;
    }
}
void solve()
{
    //주어진 S,E 오름차순 정렬
    sort(SE.begin(), SE.end(), cmp);
    printSE(SE);
    //각 부스가 끝나는 시점 저장
    vtype booth_end;
    v_vtype booth_record;
    //0 ~ N
    for (int i = 0; i < N; ++i) {
      //각 부스를 돌면서
      vtype::iterator it = booth_end.begin();
      while (it != booth_end.end()) {
          //현재 부스가 끝나는 지점 <= 직원의 시작 시간
          if (*it <= SE[i].first) {
            //현재 부스 끝나는 지점 갱신
            cout << " >> current booth updated(" << *it << " to "<< SE[i].second << ")" << endl;
            *it = SE[i].second;
            break;
          }
          ++it;
      }
      // 현재 부스가 끝나는 지점 > 직원의 시작 시간
      if (it == booth_end.end()) {
        //새로운 부스 생성
        cout << " >> (" << SE[i].first << ", " << SE[i].second  << ") new booth created" << endl;
        booth_end.push_back(SE[i].second);
      }
      //sort부스 끝나는 지점
      sort(booth_end.begin(), booth_end.end());
      //
    }
    cout << "# booth size : " << booth_end.size() << endl;
}
int main()
{
    read_input();
    solve();
    write_output();
    return 0;
}
