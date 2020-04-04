#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//var
int N = 0;
vector < pair < int, int > > SE;
//func
bool cmp(const pair <int, int > &a, const pair < int, int> &b)
{
    return a.first < b.first && a.second < b.second;
}
void read_input()
{
    cin >> N;
    for (int i = 0; i < N; ++i) {int s, e; cin >> s >> e; SE.push_back(make_pair(s,e));}
}
void write_output()
{

}
void solve()
{
    //주어진 S,E 오름차순 정렬
    sort(SE.begin(), SE.end(), cmp);
    //0 ~ N
    for (int i = 0; i < N; ++i) {
      //

    }
}
int main()
{
    read_input();
    write_output();
    return 0;
}
