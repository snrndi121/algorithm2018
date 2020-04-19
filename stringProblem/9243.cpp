#include <iostream>
using namespace std;
#define OVERWRITE(X) X == '0'? '1' : '0'
/*
  덮는 연산 : 1->0, 0->1
  n번 연산한 결과가 옳바른지 출력
*/
int main()
{
    int N; cin >> N;
    char oldBit[1000], newBit[1000];cin >> oldBit >> newBit;
    //
    bool succeed = true;
    for (int i = 0; succeed && oldBit[i] != '\0'; ++i) {
      if (N % 2 > 0)
        oldBit[i] = OVERWRITE(oldBit[i]);
      if (oldBit[i] != newBit[i]) { succeed = false;}
    }
    //
    if (succeed) cout << "Deletion succeeded";
    else cout << "Deletion failed";
    return 0;
}
