#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

/* def */
/* var */
list < int > a, b;

/* func */
int input_read();
void find_Kelement(int target);

int main()
{
    int k = input_read();
    find_Kelement(k);
    return 0;
}
int input_read()
{
    int n, k, t, mid, i = 0;
    cin >> n >> k;
    mid = n/2;

   while (i < n)
    {
        cin >> t;
        if (i < mid) { a.push_back(t);}
        else { b.push_back(t);}
        i++;
    }
    return k;
}
void find_Kelement(int target)
{
    int i = 0;
    list < int > c;
    a.sort();
    b.sort();
    /*
    list < int >::iterator ait = a.begin(), bit = b.begin();
    while (i++ < target)
    {
        int ai = *ait, bi = *bit;
        //cout << " >> com :" << ai << " - " << bi << endl;
        if (ai < bi)
        {
            c.push_back(ai);
            ait++;
        }
        else
        {
            c.push_back(bi);
            bit++;
        }
    }
    int ans = c.back();
    cout << ans << endl;
    */
    a.merge(b);
    list < int >::iterator it = a.begin();
    for (int j=0; j<target-1; ++j) {++it;}
    cout << *it <<endl;
}
