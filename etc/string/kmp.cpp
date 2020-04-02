#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


const string _H = "1232153121234215631212346215121234837121234891271212391212312128737493272934329121239238902121230380";
const string _N = "12123";

void read_input()
{

}
void printPartial(const string& _src, uint _start, uint _end)
{
  for (uint i = _start; i <= _end; ++i) {
    cout << _src[i];
  }
}
void write_output(const vector < int >& _res)
{
    cout << "H : " << _H << endl;
    for (int i = 0; i < _res.size(); ++i) {
        cout << _res[i] << endl;
        printPartial(_H, _res[i], _res[i] + _N.size() - 1);
        cout << endl;
    }
}
vector <int > getPartialMatch(const string& N)
{
    int m = N.size();
    vector < int > pi(m, 0);
    cout << " >> N :" << N << endl;
    for (int begin = 1; begin < m; ++begin) {
        cout << "# N[ begin ]:"; printPartial(N, begin, m -1); cout << endl;
        for (int i = 0; i + begin < m; ++i) {
            cout << "### N[ begin ]'s " << i << " element':" << N[begin + i] << " compare N[ i ] : " << N[ i ] << endl;
            if (N[begin + i] != N[i]) break;
            pi[ begin + i] = max(pi[ begin + i], i + 1);
        }
    }
    return pi;
}
vector < int > kmp1()
{
    vector < int > pi = getPartialMatch(_N);
    vector < int > ret;
    // cout << "ho" << endl;
    // for (uint i = 0; i < pi.size(); ++i) {
    //     cout << "pi[" << i << "] = " << pi[i] << endl;
    // }
    int n = _H.size(), m = _N.size();
    int begin  = 0, matched = 0;
    while (begin <= n - m) {
        if (matched < m && _H[begin + matched] == _N[matched]) {
            ++matched;
            if (matched == m) ret.push_back(begin);
        }
        else {
            if (matched == 0) {
                begin ++;
            } else {
                begin += matched - pi[matched - 1];
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}
vector < int > res;
int main()
{
    read_input();
    res = kmp1();
    write_output(res);
    return 0;
}
