#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;
//def
#define MAX_N 1000
#define MAX_K 500
//func
typedef struct mlistNode
{
    int id;
    mlistNode* prev, *next;
    mlistNode* operator++() {
        return next;
    }
}litsNode;

typedef struct mlist
{
    void add(int src)
    {
        mlistNode* cur = first, *pprev;//mlistNode가 양날개 포인터라서 pprev 필요함
        //마지막 노드 찾기
        while (cur != NULL) {
            pprev = cur;//현재 가리키는 값을 pprev 임시로 저장
            cur = cur->next;//현재 가리키는 값을 그것의 next로 새로 설정
        }
        //while문을 벗어난 cur는 NULL값
        cur = new mlistNode;//이후 새로 할당한 후
        //양날개를 설정해야함
        cur->prev = pprev;//왼쪽 날개는 임시로 저장했던 이전 노드, pprev
        cur->prev->next = cur;//이전 노드의 next가 NULL이었기 때문에, 새로 할당된 cur을 가리키도록
        cur->id = src;//마지막으로 cur의 id 변수를 채워주면됨.
    }
    mlistNode* erase(int tar)
    {
        mlistNode* it = first;
        for (; it != NULL; it = it->next) {
            if (tar == it->id) {
                //이전 노드의 next를 현 노드의 next
                it->prev->next = it->next;//it->next가 null이면 null대로 할당됨
                //현재가 마지막 요소가 아니라면
                if (it->next != NULL) {
                    it->next->prev = it->prev;//현 노드의 다음 노드의 prev를 현 노드의 prev로
                }
                break;
            }
        }
        return it->next;
    }
    void printList()
    {
        cout << ">> check List element (" << MAX_N << ")" << endl;
        for (mlistNode* it = first->next; it != NULL; it = it->next)
          cout << it->id << ' ';
        cout << endl;
    }
    void printList_reverse()
    {
        cout << ">> check List element (" << MAX_N << ")" << endl;
        mlistNode* it, *last_it;
        for (it = first->next; it != NULL; it = it->next) {
          last_it = it;
        }
        //reverse
        for (it = last_it; it != first; it = it->prev)
          cout << it->id << ' ';
        cout << endl;
    }
    mlist copy()
    {
        mlist res;
        for (mlistNode* it = this->first->next;
            it != NULL; it = it->next) {
            res.add(it->id);
        }
        return res;
    }
    mlistNode* first = new mlistNode;
}mlist;
//var
mlist ml;
mlistNode *lastman1, *lastman2;
int in_n, in_k;
void read_input()
{
    cout << ">> type n :"; cin >> in_n;
    cout << ">> type k :"; cin >> in_k;
    for (int i = 1; i <= in_n; ++i)
      ml.add(i);
    // ml.printList();
}
void write_output(double t)
{
    cout << "\n\n# runtime :" << t / CLOCKS_PER_SEC<< endl;
    cout << "# lastman_pair = (" << lastman1->id << ", " << lastman2->id << ")" << endl;
}
/*
n 10000,
k = 50 -> 0.107
k = 100 -> 0.111
k = 200 -> 0.114
k = 400 -> 0.124
k = 800 -> 0.145
k = 1600 -> 0.186
k = 3200 -> 0.266
k = 6400 -> 0.419
k = 12800 -> 0.730

*/
void solve1_josepus()
{
    int n = in_n;
    mlist ml_temp = ml.copy();
    mlistNode* kill = ml_temp.first->next;
    // cout << "processing now...\n";
    while (n > 2) {
      // cout << "#";
      //병사를 죽임
      kill = ml_temp.erase(kill->id);

      if (kill == NULL) { kill = ml_temp.first->next;}
      n--;
      // ml.printList();
      //kill 포인터 새로 설정
      for (int i = 0; i < in_k - 1; ++i) {
        kill = kill->next;
        if (kill == NULL) { kill = ml_temp.first->next;}
      }
    }
    lastman1 = ml_temp.first->next;
    lastman2 = lastman1->next;
}
//K가 클 때 kill 포인터 조작방법
/*
n 10000
k = 50 -> 0.107
k = 100 -> 0.111
k = 200 -> 0.114
k = 400 -> 0.124
k = 800 -> 0.145
k = 1600 -> 0.186
k = 3200 -> 0.266
k = 6400 -> 0.419
k = 12800 -> 0.730

*/
void solve2_josepus()
{
    int n = in_n;
    mlist ml_temp = ml.copy();
    mlistNode* kill = ml_temp.first->next;
    // cout << "processing now...\n";
    while (n > 2) {
      // cout << "#";
      //병사를 죽임
      kill = ml_temp.erase(kill->id);

      if (kill == NULL) { kill = ml_temp.first->next;}
      n--;
      //kill 포인터 새로 설정
      int new_k = (in_k - 1) % n;
      for (int i = 0; i < new_k; ++i) {
        kill = kill->next;
        if (kill == NULL) { kill = ml_temp.first->next;}
      }
    }
    lastman1 = ml_temp.first->next;
    lastman2 = lastman1->next;
}
int main()
{
    read_input();
    //
    clock_t start_t, end_t;
    start_t = clock();
    solve1_josepus();
    end_t = clock();
    write_output((double)(end_t - start_t));
    //
    start_t = clock();
    solve2_josepus();
    end_t = clock();
    write_output((double)(end_t - start_t));

    return 0;
}
