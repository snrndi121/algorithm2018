#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
  * 코드출처 : https://yabmoons.tistory.com/287
  * 문제 : 테트리스를 빙자한 최대값구하기
  * 조건
    - 4가지 블록, 각 블록은 90씩 회전 가능
    - 정방 매트릭스, N * N
      - 매트릭스 단일 블록 최대값 k <= 1,000,000
      - 4 <= N <= 100
    - 입력 마지막줄에는 0이 주어진다
  * 출력 : 각 테스트케이스별 최대값 구해라
*/
int N;
int** matrix;
long searchBlock(int _x, int _y, int _block)
{
    long local_max = 0, t1, t2;
    //shape1
    if (_block == 0) {
        //check-range
        if (_x + 3 < N) { t1 = matrix[_x][_y]+matrix[_x+1][_y]+matrix[_x+2][_y]+matrix[_x+3][_y];}
        if (_y + 3 < N) { t2 = matrix[_x][_y]+matrix[_x][_y+1]+matrix[_x][_y+2]+matrix[_x][_y+3];}
    }
    //shape2
    else if (_block == 1) {
      //check-range
        if (_x + 2 < N) {
          if (_y - 1 > 0) t1 = matrix[_x][_y]+matrix[_x+1][_y]+matrix[_x+1][_y-1]+matrix[_x+2][_y];
          if (_y + 1 < N) t2 = matrix[_x][_y]+matrix[_x+1][_y]+matrix[_x+1][_y+1]+matrix[_x+2][_y];
        }
        local_max = t1 > t2? t1 : t2;
        if (_y + 2 < N) {
            if (_x + 1 < N) { t1 = matrix[_x][_y]+matrix[_x][_y+1]+matrix[_x+1][_y+1]+matrix[_x][_y+2];}
            if (_x - 1 > 0) { t2 = matrix[_x][_y]+matrix[_x][_y+1]+matrix[_x-1][_y+1]+matrix[_x][_y+2];}
        }
        local_max = t1 > t2? t1 : t2;
    }
    //shape3
    else if (_block == 2) {
        //check-range
        if (_x + 1 < N && _y + 2 < N) { t1 = matrix[_x][_y]+matrix[_x][_y+1]+matrix[_x+1][_y+1]+matrix[_x+1][_y+2];}
        if (_x + 2 < N && _y - 1 > 0) { t2 = matrix[_x][_y]+matrix[_x+1][_y]+matrix[_x+1][_y-1]+matrix[_x+2][_y-1];}
        local_max = t1 > t2? t1 : t2;
    }
    //shape4
    else if (_block == 3) {
        //check-range00
        if (_x + 1 < N && _y + 1 < N) { local_max = matrix[_x][_y]+matrix[_x][_y+1]+matrix[_x+1][_y]+matrix[_x+1][_y+1];}
    }

    //shape5
    else {
        //check-range
        if (_x + 1 < N) {
            if (_y + 2 < N) {
                t1 = matrix[_x][_y]+matrix[_x+1][_y]+matrix[_x+1][_y+1]+matrix[_x+1][_y+2];
                t2 = matrix[_x][_y]+matrix[_x+1][_y]+matrix[_x][_y+1]+matrix[_x][_y+2];
            }
        }
        local_max = t1 > t2? t1 : t2;
        if (_y + 1 < N) {
            if (_x - 2 > 0) { t1 = matrix[_x][_y]+matrix[_x][_y+1]+matrix[_x-1][_y+1]+matrix[_x-2][_y+1];}
            if (_x + 2 < N) { t2 = matrix[_x][_y]+matrix[_x][_y+1]+matrix[_x+1][_y]+matrix[_x+2][_y];}
        }
        local_max = t1 > t2? t1 : t2;
    }
    return local_max;
}
int main()
{
    cin >> N;
    matrix = new int*[N];for (int r = 0; r < N; ++r) { matrix[r] = new int[N];}
    //입력
    for (int r = 0; r < N; ++r)
        for (int c = 0 ; c < N; ++c)
            scanf("%d", &matrix[r][c]);

    long global_max = 0;
    //본격
    for (int r = 0; r < N; ++r) {
        for (int c = 0 ; c < N; ++c ) {
            //특정 지점에서 시작
            for (int b = 0; b < 4; ++b) {
                long local_max = searchBlock(r, c, b);
                global_max = global_max < local_max? local_max : global_max;
            }
        }
    }
    cout << endl << global_max << endl;
    // //출력
    return 0;
}
