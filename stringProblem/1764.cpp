#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*
  * 중복된 단어를 찾아, 사전 순으로 출력해라
  * N, M <= 500,000
*/
/*
  * 전처리 : 문자열 정렬
  * 로직 (1) : 바로 옆만 확인한다.
*/
bool cmp(const char* a, const char* b)
{
    return strcmp(a, b) < 0;
}
int main()
{
    //입력
    int N, M; cin >> N >> M;int inSize = N + M;
    char** namelist = new char*[inSize];//2차원배열
    for (int i = 0 ; i < inSize; ++i) {char* buffer = new char[21]; cin >> buffer; namelist[i] = buffer;}
    char buffer[20] = "dfdf";
    cout << buffer << endl;
    flush(buffer);
    // 전처리
    sort(namelist, namelist+inSize, cmp);
    //로직 (1)
    int *res = new int[inSize/2]; int idx = 0;
    for (int begin = 0 ; begin < inSize-1; ++begin) {
        //같은 문자열의 위치를 기억, 그리고 다음으로 건너뛴다.
        if (strcmp(namelist[begin], namelist[begin + 1]) == 0) { res[idx++] = begin; begin += 1;}
    }
    //
    cout << idx << endl;
    for (int i = 0; i < idx; ++i) { cout << namelist[res[i]] << endl;}
    return 0;
}
