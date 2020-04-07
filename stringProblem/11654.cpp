#include <iostream>

using namespace std;

char read_input()
{
    char _in;
    cin >> _in;
    return _in;
}
int solve(char _arg)
{
    return _arg;
}
void write_output(int _arg)
{
    cout << _arg;
}
int main() {
   char _in = read_input();
   int _res = solve(_in);
   write_output(_res);
   return 0;
}
