#include <iostream>
#include <vector>

using namespace std;

//var
int N, M;
int t_x, t_y;

void read_input()
{
    cin >> N >> M;
    cin >> t_y >> t_x;
}
void write_output()
{

}
uint getFactorial(uint _src)
{
    uint res = 1;
    for (int i = 1; i <= _src; ++i) { res *= i;}
    return res;
}
void solve()
{
    int min_time = 0, accident = 0;
    //exception
    if (t_y >= N || t_x >= M ||
        (t_y == 0 && t_x == 0))
        return ;
    int temp_x = t_x, temp_y = t_y;
    accident = getFactorial(temp_x + temp_y);
    accident /= getFactorial(temp_x);
    accident /= getFactorial(temp_y);
    min_time = temp_x + temp_y;

    cout << " # time :" << min_time << endl;
    cout << " # accident :" << accident << endl;
}
int main()
{
    read_input();
    solve();
    write_output();
    return 0;
}
