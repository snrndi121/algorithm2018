#include <iostream>

using namespace std;
//def
#define MAX_N 10
#define MAX_K 3
//func
typedef struct mlistNode
{
    int id;
    mlistNode* prev, *next;
    mlistNode* operator++() {
        return this->next;
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
        cout << "> tar : " << tar << endl;
        mlistNode* it = first->next;
        for (; it != NULL; it = it->next) {
            if (tar == it->id) {
                cout << " > tar :" << tar << " found!!!" << endl;
                it->prev->next = it->next;
                if (it->next != NULL)//현재가 마지막 요소가 아니라면
                  it->next->prev = it->prev;
                break;
            }
        }
        return it->next;
    }
    void printList()
    {
        cout << "\n>> check List element (" << MAX_N << ")" << endl;
        for (mlistNode* it = first->next; it != NULL; it = it->next)
          cout << it->id << ' ';
        cout << endl;
    }
    void printList_reverse()
    {
        cout << "\n>> check List element (" << MAX_N << ")" << endl;
        mlistNode* it, *last_it;
        for (it = first->next; it != NULL; it = it->next) {
          last_it = it;
        }
        //reverse
        for (it = last_it; it != first; it = it->prev)
          cout << it->id << ' ';
        cout << endl;
    }
    mlistNode* first = new mlistNode;
}mlist;
//var
mlist ml;

void read_input()
{
    for (int i = 1; i <= MAX_N; ++i)
      ml.add(i);
    ml.printList();
}
void write_output()
{

}
void solve_josepus()
{
    int n = MAX_N;
    mlistNode* kill = ml.first->next;
    while (n > 2) {
      //병사를 죽임
      kill = ml.erase(kill->id);
      n--;
      ml.printList();
      //kill 포인터 새로 설정
      for (int i = 0; i < MAX_K - 1; ++i) {
        kill++;
        if (kill == NULL) { kill = ml.first->next;}
      }
    }
}
int main()
{
    read_input();
    solve_josepus();
    write_output();
    return 0;
}
