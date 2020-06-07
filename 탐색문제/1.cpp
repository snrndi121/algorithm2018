#include <iostream>
#include <vector>
#include <climits>

using namespace std;


//def
typedef pair < string, string > ss_ptype;
typedef pair < int, int > ii_ptype;
typedef vector < int > i_vtype;
typedef vector < ii_ptype > ii_pvtype;
//func
//var
vector < ss_ptype > cvt_matrix;
vector < ss_ptype > cvt_tar;
i_vtype  cvt_weight;
i_vtype answer;

int CVT_SIZE;

/*
6
ox oo 3
ox xo 2
ox xx 4
xo oo 3
xo xx 1
xx oo 10
3
xooxoox xoooxoo
xoxxoxx xooxxoo
xooxoox xoxoxox
*/
void input()
{
    //convert-matrix;
    int n ;
    cin >> n;
    string left, right; int weight;
    for (int i = 0; i < n; ++i) {
        cin >> left >> right >> weight;
        cvt_matrix.push_back(make_pair(left, right));
        cvt_weight.push_back(weight);
    }
    CVT_SIZE = cvt_matrix[0].first.size();
    //testcase;
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; ++i) {
        cin >> left >> right;
        cvt_tar.push_back(make_pair(left, right));
    }
    //init
    for (int i = 0; i < testcase; ++i) { answer.push_back(INT_MAX);}
}
ii_pvtype getCandidateCVT(string& src, int start)
{
    ii_pvtype res;
    string tar = src.substr(start, CVT_SIZE);
    //cvt_matrix 순회
    for (int i = 0; i < cvt_matrix.size(); ++i) {
        if (cvt_matrix[i].first == tar) {//convert to Right
            res.push_back(make_pair(i, 1));
        }
        else if (cvt_matrix[i].second == tar) {//convert to left
            res.push_back(make_pair(i, 0));
        }
    }
    return res;
}
int dfs(ss_ptype tar, int cost)//( (source, target), cur_index, cost)
{
    cout << "\n > src :" << tar.first;
    cout << "\n > tar :" << tar.second << endl;
    //escape-condition
    int left = tar.first.size();
    if (left == 0) { return 1;}
    //다른 지점 찾기
    int here = 0;
    for (; here < left && tar.first[here] == tar.second[here]; ++here){;}
    if (here == left) { return cost;}

    //recursive-start
    string new_src = tar.first;
    cout << " > origin_src :" << new_src << endl;
    ii_pvtype cvt_list = getCandidateCVT(new_src, here - 1);//(source, start_index)
    cout << "#can :" << cvt_list.size() << " possible now" << endl;
    for (ii_pvtype::iterator it = cvt_list.begin(); it != cvt_list.end(); ++it) {
        //치환
        string token = it->second == 0? cvt_matrix[it->first].first : cvt_matrix[it->first].second;
        new_src.replace(here, CVT_SIZE, token);
        cout << " > cvt To:" << new_src << endl;
        cost += cvt_weight[it->first];
        int left_sz = tar.first.size() - here;
        int res = dfs(make_pair(new_src.substr(here, left_sz), tar.second.substr(here, left_sz)), cost);
        if (res > 0) {
            return cost;
        }
    }
    cout << "> matrix failed \n";
    return 0;
}
void solution()
{
    cout << "s" << endl;
    //전체 테스크 케이스 순회
    for (int i = 0; i < cvt_tar.size(); ++i) {
        //가능한 집합 고려
        cout << "> cycle start" << endl;
        int res = dfs(cvt_tar[i], 0);//( (source, target), cur_index, cost)
        //i_vtype cost;
        if (res == 0) { cout << "  > failed" << endl;}
        else { answer[i] = res; }//sucostccess
    }
}
void ouput()
{
    cout << "> res " << endl;
    for (int i = 0; i < answer.size(); ++i) { cout << "(" << i << ")->" << answer[i] << endl;}
}
int main()
{
    input();
    solution();
    ouput();
}

