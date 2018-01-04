#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* To solve this */
/*
  First, we need to schedule the given time in samll order. Then, calculate each waiting time.
  The key is to calculate accumulated times from short times.

*/
/* var */
vector < int > input;

/* func */
void input_read();
int data_scheduling();

int main()
{
    input_read();
    int min_time = data_scheduling();
    cout << min_time << endl;
    return 0;
}
void input_read()
{
    int _size, _n;
    cin >> _size;
    while(_size-- > 0)
    {
        cin >> _n;
        input.push_back(_n);
    }
}
int data_scheduling(void)
{
    //part1. sort by ascend
    sort(input.begin(), input.end());

    //part2. weighted scheduling
    vector < int >::iterator it=input.begin();
    int accumulated_time=0, total_time=0;
    for(; it != input.end(); ++it)
    {
        int _curTime = (*it);
        accumulated_time += _curTime;
        total_time += accumulated_time;
    }
    return total_time;
}
