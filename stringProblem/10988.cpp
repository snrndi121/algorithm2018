#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char _input[100]; cin >>_input;
    int size = 0;while (_input[++size] != '\0');
    bool res = true;
    for (int i = 0; res && i < size/2; ++i) {res = _input[i] == _input[size-1-i];}
    cout << res << endl;
    return 0;
}
