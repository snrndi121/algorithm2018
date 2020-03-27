#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

//description
//trakter's move range : N-1, N+1, 2*N
//var
int tracker, target;
int count;
//func
void read_input()
{
    cin >> tracker >> target;
}
int getCount()
{
  int time = 0;
  bool visit[100001][2];
  queue <pair<int, int> > myque;
  memset(visit, 0, sizeof(visit));
  myque.push(make_pair(tracker, 0));

  while (1) {
    target += time;
    if (target > 100000)
      return -1;
    if (visit[target][time % 2])
      return time;

    for (int i = 0, size = myque.size(); i < size; i++) {
      int currentPosition = myque.front().first;
      int newTime = (myque.front().second + 1) % 2;
      int newPosition;

      myque.pop();

      //동작1.뒤로 갔을 경우
      newPosition = currentPosition - 1;
      //이 값이 0보다 크고 그 때의 위치에서 -1 동작을 해본 적이 없다면
      if (newPosition >= 0 && !visit[newPosition][newTime]) {
          visit[newPosition][newTime] = true;
          myque.push(make_pair(newPosition, newTime));
      }
      //동작2.앞으로 갔을 경우
      newPosition = currentPosition + 1;
      //이 값이 최대값을 초과하지 않고 +1 동작을 해본 적이 있다면
      if (newPosition < 100001 && !visit[newPosition][newTime]) {
        visit[newPosition][newTime] = true;
        myque.push(make_pair(newPosition, newTime));
      }
      //동작3.두배 앞으로 갔을 경우
      newPosition = currentPosition * 2;
      //이 값이 최대값을 초과하지 않고 *2 동작을 해본 적이 있다면
      if (newPosition < 100001 && !visit[newPosition][newTime]) {
        visit[newPosition][newTime] = true;
        myque.push(make_pair(newPosition, newTime)); }
      }
      //전반적으로 보면 최적이라기보다는
      //이 동작을 할 수 있다면 해버리고, visit 변수에 의해서
      //다른 삽입을 막게됨

      //다음초
      time++;
    }
    count = time;
}
void write_output()
{
    cout << time;
}
int main()
{
    read_input();
    getCount();
    write_output();
    return 0;
}
