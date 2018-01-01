#include <iostream>
#include <vector>

using namespace std;

/* To solve this...

- Divide a given number(K) by a proper number(=coin) in big order. Then remember the quotient and add it to
  'count'. Besides, the remainder will be a new K.

- Finally we can get the number of coins to give back to change.
*/

/* var */
vector < int > coin;
int target=0;

/* func */
void input_read();
void find_minCoin();
int pickcoin(int _target);

int main()
{
    input_read();
    find_minCoin();
    return 0;
}
void input_read()
{
    int n=0, c=0, t=0;
    cin >> n >> t;
    while(n-- > 0)
    {
        cin >> c;
        coin.push_back(c);
    }
    target=t;
}
void find_minCoin()
{
    int count=0, temp=target;
    while(temp != 0)
    {
        int i=pickcoin(temp);
        if(i < 0) { cout << "wrong"; break;}
        //cout << " >> coin :" << coin[i] << endl;
        count += (temp / coin[i]);
        //cout << " count :" << count << endl;
        temp = (temp % coin[i]);
    }
    cout << count;
}
int pickcoin(int _target)
{
    unsigned i=coin.size() - 1;
    for(; i >= 0; --i)
    {
        int _coin=coin[i];
        if(_coin <= _target) { return i;}
    }
    return -1;
}
