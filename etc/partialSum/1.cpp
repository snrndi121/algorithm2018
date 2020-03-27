#include <iostream>

using namespace std;

int presentMax, childNum;
int* presentNum;
void read_input()
{
    cin >> presentMax >> childNum;
    presentNum = new int[presentMax];
    for(int i = 0; i < presentMax; ++i)
      cin >> presentNum[i];
}
int solve()
{
    //var
    int** resQ2;
    resQ2 = new int*[presentMax];
    //caculate partialSum
    int partialSum[presentMax] = {presentNum[0],};
    for (int i = 1; i < presentMax; ++i)
      partialSum[i] = partialSum[i - 1] + presentNum[i];

    //Q1.한 번 주문할 수 있다면 가능한 주문 방법은 몇 가지일까? (연속된 구간을 요청함)
    //Brute force 방식
    //sample
    /*
    6 4
    1 2 3 4 5 6

    */
    int res = 0, partialQ1 = 0;
    cout << " >> when a = 0, then" << endl;
    for (int b = 0; b < presentMax; ++b) {
      if (partialSum[b] % childNum == 0) res++;
    }
    //(0,0), (0,1), (0,2), (0,3), (0,4), (0,5)
    cout << " >> when a = 0, then" << endl;
    for (int a = 1; a < presentMax -1; ++a) {
        //(b, a)
        int* elementQ2 = new int[presentMax - a -1];
        int i = 0;
        for (int b = a + 1; b < presentMax; ++b) {
            //구간값; partialSum [b, a]
            partialQ1 = partialSum[b] - partialSum[a - 1];
            //partial[b] - partial[a] mod childNum == 0, 인 경우의 수를 구하면 됨
            cout << partialQ1 << ' '; //질문 2를 풀기 위해서는 temp 2를 기억해둬야함.
            elementQ2[i++] = partialQ1;
            if (partialQ1 % childNum == 0)
              res++;
        }
        resQ2[a - 1] = elementQ2;
        cout << endl;
    }
    //Q2
    for (int i = 0; i < presentMax - 1; ++i)
    {
        cout << "[ " << i << "] : ";
        for (int j = 0; j < presentMax - (2 + i); ++j)
        {
          cout << resQ2[i][j] << ' ';
        }
        cout << endl;
    }
    return res;
    //0~max, 1~max, 2~max, max-1~max
    //partial[b] - partial[b-1] = presentNum
}

//Q2.여러 번 주문할 수 있다면 주문이 겹치지 않게 최대 몇번 주문할 수 있을까?
void write_output(int res = 0)
{
    cout << ">> 가능한 경우의 수는 : " << res << endl;
}
int main()
{
    read_input();
    write_output(solve());
    return 0;
}
