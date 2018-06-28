/* To solve this
  1. We need to get a reccurence relation about this problem.
  2. A normal equation is accumWeight[i] = accumWeight[i - 1] + 1
    (Because location[i] is bigger than location[i - 1] by 1. According to the condition of the problem,
      operation(3) will be run.)
  3. Operation (1) and (2) are special cases. Therefore, We will compare those values with the before value we have
    already got above.
*/
#include <iostream>
#include <vector>
using namespace std;

/* def */
#define REM2(a) (a) % 2 //remainder
#define REM3(a) (a) % 3
#define QUO2(a) (a) / 2 //quotient
#define QUO3(a) (a) / 3

/* var */
int dividend;

/* func */
void input_read();
void count_remainder();

int main()
{
    input_read();
    count_remainder();
    return 0;
}
void input_read()
{
    cin >> dividend;
}
void count_remainder()
{
    /* Initializing */
    int i = 2;
    int* accumWeight = new int[dividend + 1];

    /* Accumulating */
    while(i <= dividend)
    {
        /* handling about operation(3) */
        accumWeight[i] = accumWeight[i - 1] + 1;

        /* handling about operation(1) */
        if (REM3(i) == 0)
        {
            accumWeight[i] = min(accumWeight[i], accumWeight[QUO3(i)] + 1);
        }
        /* handling about operation(2) */
        if (REM2(i) == 0)
        {
            accumWeight[i] = min(accumWeight[i], accumWeight[QUO2(i)] + 1);
        }
        i++;
    }
    cout << accumWeight[i - 1] << endl;
}
