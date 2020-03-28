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
int *mheight, *mleft, *mright;

//func
void read_input()
{
    cout << "# read_input" << endl;
    mheight = new int[FENCE_LEN];
    mleft = new int[FENCE_LEN];
    mright = new int[FENCE_LEN];
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        mheight[i] = rand() % FENCE_LEN + 1;
    }
    mleft[0] = -1;
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
    for (int i = 1; i < FENCE_LEN; ++i) {
        //일단 스택에 넣는 행위는 맞지가 않음
        int prev_idx = i -1;
        //그 이전에
        while (!determin_yet.empty() && mheight[prev_idx] >= mheight[i]) {
            mright[prev_idx] = i - 1;
            determin_yet.pop();
            prev_idx = determin_yet.top();
            if (mheight[prev_idx] < mheight[i]) {
                determin_yet.push(prev_idx);
            }
        }
        //스택에 추가함
        if (mheight [prev_idx] < mheight[i]) {
            mleft[i] = i;
            determin_yet.push(i);
        }
    }
}
void write_output()
{
    cout << "# write_output" << endl;
    for (int i = 0; i < FENCE_LEN; ++i) {
        cout << "(" << i << ")" << "mleft : " << mleft[i] << ", mright : " << mright[i] << endl;
    }
}
int main()
{
    read_input();
    solve_sweep();
    write_output();
    return 0;
}
