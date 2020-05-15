#include <iostream>

using namespace std;

int main()
{
    int CASE_N, N;
    int** _inputArr;
    cin >> CASE_N;
    _inputArr = new int*[CASE_N];
    //입력
    for (int i = 0; i < CASE_N; ++i) {
        cin >> N;
        _inputArr[i] = new int[N+1];
        _inputArr[i][0] = N;
        for (int j = 1; j < N+1; ++j) { cin >> _inputArr[i][j];}
    }
    //삽입정렬
    for (int i = 0; i < CASE_N; ++i) {
        for (int j = 2; j < _inputArr[i][0]+1; ++j) {
            for (int k = 1; k < _inputArr[i][0]; ++k) {
                if (_inputArr[i][k] > _inputArr[i][j]) {
                    //switch
                    int temp = _inputArr[i][k];
                    _inputArr[i][k] = _inputArr[i][j];
                    _inputArr[i][j] = temp;
                }
            }
        }
    }
    //출력 :
    for (int i = 0; i < CASE_N; ++i) {
        cout << "#" << i + 1 << ' ';
        for (int j = 1; j < _inputArr[i][0]+1; ++j) {
            cout << _inputArr[i][j] << ' ';
        }
        cout << endl << endl;
    }
    return 0;
}
