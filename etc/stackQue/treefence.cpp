/*
  * 스위핑 알고리즘 : 한 지점의 공간에서부터 시작해서 끝으로 이동하면서 쓸어담아내듯이 해결하는 알고리즘
*/
#include <iostream>
#include <stack>
#include <time.h>

using namespace std;
//def
#define FENCE_LEN 10
//var
int *mheight, *mleft, *mright, *mwidth;

//func
void read_input()
{
    cout << "# read_input" << endl;
    mheight = new int[FENCE_LEN];
    mleft = new int[FENCE_LEN];
    mright = new int[FENCE_LEN];
    mwidth = new int[FENCE_LEN];
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        mheight[i] = rand() % FENCE_LEN + 1;
        cout << mheight[i] << ' ';
    }
    mheight[0] = -1;
}
/*
  * sweepping
    - 맨 끝 지점에서 시작해서
    - 현재 i 번째 판자의 왼쪽과 비교해나간다.
    - mright가 결정되지 못 한 녀석은 스택에 넣는다.
*/
/*
판자 배열 = {-1, 3, 5, 10, 4, 3, 3, 1, -1}
*/
void solve_sweep()
{
    cout << "# solve_sweep" << endl;
    stack < int > determin_yet;
    int res = 0;
    for (int i = 1; i < FENCE_LEN; ++i) {
        while(!determin_yet.empty() && mheight[determin_yet.top()] >= mheight[i]) {
            int j = determin_yet.top();
            cout << "(" << mheight[ j ] << ", " << mheight[ i ] << ")" << endl;
            determin_yet.pop();
            int width = -1;
            if (determin_yet.empty()) {
                cout << " > its left side is empty" << endl;
                width = i;
            } else {
                cout << " > its left side exists" << endl;
                width = (i - determin_yet.top() - 1);
            }
            res = max(res, mheight[i] * width);
            mwidth[i] = res;
        }
        cout << ">> new val(" << mheight[i] << ") is added" << endl;
        determin_yet.push(i);
    }
    cout << " answer : " << res << endl;
}
void write_output()
{
    cout << "# write_output" << endl;
    for (int i = 0; i < FENCE_LEN; ++i) {
        // cout << "(" << mheight[i] << ")" << "mleft : " << mleft[i] << ", mright : " << mright[i] << endl;
        cout << "(" << mheight[i] << ") width :" << mwidth[i] << endl;
    }
}
int main()
{
    read_input();
    solve_sweep();
    write_output();
    return 0;
}
