/*
  * 스위핑 알고리즘 : 한 지점의 공간에서부터 시작해서 끝으로 이동하면서 쓸어담아내듯이 해결하는 알고리즘
*/
#include <iostream>
#include <stack>
#include <time.h>

using namespace std;
//def
#define FENCE_LEN 1000
//var
int *height, *left, *right;

//func
bool cmpHeight(int i, int j) const {return height[i] < height[j]? i : j;}
void read_input()
{
    height = new int[FENCE_LEN];
    left = new int[FENCE_LEN];
    right = new int[FENCE_LEN];
    srand(time(NULL));
    for (int i = 0; i < FENCE_LEN; ++i) {
        height[i] = rand() % FENCE_LEN + 1;
    }
    left[0] = -1;
}
/*
  * sweepping
    - 맨 끝 지점에서 시작해서
    - 현재 i 번째 판자의 왼쪽과 비교해나간다.
    - right가 결정되지 못 한 녀석은 스택에 넣는다.
*/
/*
판자 배열 = {-1, 3, 5, 10, 4, 3, 3, 1, -1}
*/
void solve_sweep()
{
    stack < int > determin_yet;
    for (int i = 1; i < FENCE_LEN; ++i) {
        while (!determin_yet.empty() && height[i-1] >= height[i]) {
          int prev_idx = determin_yet.pop();
          if (height[prev_idx] < height[i]) {
              determin_yet.push(prev_idx);
          } else {
              right [prev_idx] = i - 1;
          }
        }
        if (height[i - 1] < height[i]) {
            left[i] = i;
            determin_yet.push(i);
        }
    }
}
void write_output()
{

}
int main()
{
    read_input();
    solve_sweep();
    write_output();
    return 0;
}
