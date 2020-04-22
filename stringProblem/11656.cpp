#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct suffixCMP {
    char* s;
    suffixCMP(char *_s):s(_s){}
    bool operator()(int i, int j) {
        return strcmp(s+i, s+j)<0;
    }
};
int main()
{
    char _input[10001];cin>>_input;
    short size=0;
    short res[size];
    while(_input[size]!='\0') {res[size]=size++;}
    //
    sort(res, res+size, suffixCMP(_input));
    for (int i = 0; i < size; ++i) {
        cout << _input + res[i] << endl;
    }
    return 0;
}
