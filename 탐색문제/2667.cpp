#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
/*
  * 문제 : DFS와 BFS 사용해서 군집 여부 판단
  * 출력 : 각 군집 집단 소속 인원 수
  * 코드 출처 : github @twpower 님
*/
char** apart;//단지 정보
int* groups;//그룹 멤버수 담는 변수
int group_id = 0;//그룹 ID
bool* isvisited;//방문 여부
int N = 0;
//방향성 = {왼, 아래, 오른, 위}
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void searchBFS(int _x, int _y)
{
      //part4.해당 집 수를 다 구하면 해당 집의 ID를 인덱스로하는 배열에 추가해준다.
      isvisited[_x * N  + _y] = true;
      groups[group_id]++;

      for (int i = 0; i < 4; ++i) {//4방향에 대하여
          int next_x = _x + dx[i];
          int next_y = _y + dy[i];

          if (0 <= next_x && next_x < N && 0 <= next_y && next_y < N) {//새로운 방문 지점에 대하여 유효성 검사
              if (apart[next_x][next_y] == '1' && !isvisited[next_x * N + next_y]) {//단지 정보 검사
                  searchBFS(next_x, next_y);
              }
          }
      }
}
int main()
{
    cin >> N;
    apart = new char* [N];//매트릭스
    isvisited = new bool[N*N];
    groups = new int[N*N];
    for (int i = 0; i < N; ++i) {
        char* one_line = new char[N];
        scanf("%s", one_line);
        apart[i] = one_line;
    }
    //part1.전체 지도를 보면서 집이 있는지
    for (int i = 0; i < N*N; ++i) {
        //방문하지 않았다면
        //part2.집 발견하면 단지로 정의하고 ID를 부여(= i를 ID 생각할거임)
        // cout << "\n#cur point :" << i/N << ", " << i%N << endl;
        if (apart[i/N][i % N] == '1' && !isvisited[i]) {
            group_id++;
            //part3.BFS또는 DFS 통해 해당 단지의 집수를 구해라
            searchBFS(i / N, i % N);
        }
    }
    //part5.전체 지도의 탐색이 다 끝나면 배열을 오름차순 정렬하고 출력한다.
    sort(groups + 1, groups + group_id + 1);
    for (int i = 1; i <= group_id; ++i) { cout << groups[i] << endl;}
    return 0;
}
