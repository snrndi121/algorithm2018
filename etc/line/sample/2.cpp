#include <iostream>
#include <vector>
#include <algorithm>

/*
  * 개념 : 조합과 K번째 구하기
  * 풀이 : 입력 사이즈 크기와 상관없이 트립을 만들어 보려고함
        ~ 그러나 트립의 개념이 헷갈려서 풀지 못함.
  * 결과 : 사이즈 3! 이니깐 직접 배열 삽입으로 강사는 풀어냄
*/
using namespace std;
//def
#define NUM 3
#define NEXT(a) (a % NUM)

//var
int* card = nullptr;
int K = 0;
int res = 0;
void read_input()
{
    card = new int[NUM];
    for (int i = 0; i < NUM; ++i)
      cin >> card[i];
    cin >> K;
}
void write_output()
{
    cout << res << endl;
}
void solution()
{
    sort(card, card + NUM);
    int mlist[10][10] = {0,};
    int index = 0;
    for (int i = 0; i < 6; ++i) {

      mlist[i][0] = card[NEXT(index)];
      mlist[i][1] = card[NEXT(index + 1)];
      mlist[i][2] = card[NEXT(index + 2)];

      mlist[i][0] = card[NEXT(index)];
      mlist[i][1] = card[NEXT(index + 1)];
      mlist[i][2] = card[NEXT(index + 2)];

      cout << "mlist[K-1][0] :" << mlist[i][0] << endl;
      cout << "mlist[K-1][1] :" << mlist[i][1] << endl;
      cout << "mlist[K-1][2] :" << mlist[i][2] << endl;
      index++;
    }

    res = mlist[K-1][0] * 100 + mlist[K-1][1] * 10 + mlist[K-1][2];
}
int main()
{
    read_input();
    solution();
    write_output();
    return 0;
}
