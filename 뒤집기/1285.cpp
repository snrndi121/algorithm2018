#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

/*
  * 문제 : 동전 뒤집기
  * 조건
    - 한 열, 한 행 묶음으로 뒤집는다.
    - 뒤집은 결과 T의 개수 >= 2,
  * 출력 : 뒤집어서 최소의 T의 개수는 얼마냐
    - 2를 만들수 있냐
    - 그 근처까지 뒤집어봐라
*/
int main()
{
    //입력
    char coin[20][20];
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
    		for (int j = 0; j < N; j++) {
      			while (true) {
        				scanf("%c", &coin[i][j]);
                if (coin[i][j] != '\n') break;
      			}
    		}
  	}
    //풀이
    int ans = N * N;
    //K, 뒤집는 횟수 
    for (int k = 0; k < (1 << N); k++) {
        int sum = 0;
        //하나의 열에 대하여
        for (int col = 0; col < N; col++) {
            int nowT = 0;//현재 열에 뒤집힌 T의 개수
            //col형에 대하여 각 row를 뒤집어봄
            for (int row = 0; row < N; row++) {
                char state = coin[row][col];//현재 뒤집힌 상태
                //뒤집을 조합을 만들어내는 부분
                if ((1 << row) & k) {//뒤집기 시행
                    if (state == 'T') state = 'H';
                    else state = 'T';
                }
                //현재 뒷면이면 뒷면 수를 카운트함
                if (state == 'T') nowT++;
            }
            /*
              * nowT는 현재 뒤집혀 있는 T임
              * N - nowT는 그것의 역이라고 보면됨.
              * 한 열을 뒤집는 행위는 매번 역전값임. 앞->뒤, 뒤->앞으로 바꾸는 행위
              * 그래서 현재 T가 5개 뒤집혀있고, N이 8개라면
              * 한 번 뒤집어 버려서 8 - 5 = 3을 취하는게 바른 값이고
              * 그게 MIN(nowT, N - nowT)
            */
            sum += min(nowT, N - nowT);
        }
        ans = min(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}
