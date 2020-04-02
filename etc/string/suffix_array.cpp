#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

//def
struct suffixComparator {
  const string& s;
  suffixComparator(const string& s) : s(s) {}
  bool operator()(int i, int j) {
      return strcmp(s.c_str() + i, s.c_str() + j) < 0;
  }
};
//var
const string S = "ababkdkcdleldflelf";
vector < int > res;
//func
void read_input()
{

}
void printPatial(const string& s, uint _start, uint _end)
{
    for (int i = _start; i < _end; ++i)
        cout << s[i];
    cout << endl;
}
void write_output(const vector < int > &s)
{
    for (auto i : s) {
        printPatial(S, i, i + S.size() - 1);
    }
}
vector < int > getSuffixArray()
{
    vector < int > perm;
    for (int i = 0; i < S.size(); ++i) perm.push_back(i);
    sort(perm.begin(), perm.end(), suffixComparator(S));
    return perm;
}
int main()
{
    read_input();
    // res = getSuffixArray();
    // write_output(res);
    const string s = "243";
    cout << s.c_str() + 1<< endl;
    return 0;
}
