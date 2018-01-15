#include <iostream>
#include <vector>

using namespace std;

/* def */
/* var */
int sizeOfstairs;
vector < int > stairs;

/* func */
void input_read();
void step_stairs();
int includeStairs(int cur, int* aw, int* tsc);
int excludeStairs(int cur, int* aw);

int main(void)
{
    input_read();
    step_stairs();
    return 0;
}
void input_read()
{
    int i=0;
    cin >> sizeOfstairs;
    stairs.reserve(sizeOfstairs);

    while(i < sizeOfstairs)
    {
        cin >> stairs[i++];
    }
}
void step_stairs()
{
    int* accum_weight = new int[sizeOfstairs];
    bool* visit = new bool[sizeOfstairs];
    accum_weight[0] = stairs[0];
    int twostepCount = 0, res = 0;
    for ( int i = 0; i < sizeOfstairs; ++i) { visit[i] = false;}

    for (int curStep = 0; curStep < sizeOfstairs; ++curStep)
    {
        cout << "\n > current stairs :" << stairs[curStep] << endl;
        int incost = includeStairs(curStep, accum_weight, &twostepCount),
            excost = excludeStairs(curStep, accum_weight);

        cout << " > incost :" << incost << ", " << "excost :" << excost << endl;
        accum_weight[curStep] = max(incost, excost);
        if ( incost < excost ) { twostepCount = 0;}

        cout << " > accum_weight :" << accum_weight[curStep] << endl;
        if ( curStep == sizeOfstairs - 1) { res = incost;}
    }
    cout << " > res : " << res << endl;
}
int includeStairs(int cur, int* aw, int* tsc)
{
    cout << " > tsc :" << *tsc << "->";
    if(cur > 0)
    {
        if((*tsc) == 2)
        {
            /*
              * ------------------------------
              * |   i-2   |   i-1   |    i   |
              *-------------------------------
              *
              * If the selected stairs are stairs(i) and stairs(i-2), then discount the stepcounter, 'tsc' by 1.
              * Otherwise, it doesn't change it.
            */
            int selVal = max(stairs[cur - 1], stairs[cur - 2]);
            if(selVal != stairs[cur - 1])
            {
                (*tsc)--;
                if ( cur > 3)
                {
                    cout << " > incost in aw[i-3] :" << aw[cur - 4] << endl;
                    return stairs[cur] + selVal + aw[cur - 4];
                }
            }
            else  /* [ i-1, i ] */
            {
                if ( cur - 3 == 0) { selVal = stairs[cur - 2];} /* stairs[0], not step prevetion */
                if ( cur > 2)
                {
                    cout << " > incost in aw[i-3] :" << aw[cur - 3] << endl;
                    return stairs[cur] + selVal + aw[cur - 3];
                }
            }

            cout << *tsc << endl;
            return stairs[cur] + selVal;
        }
        else  /* tsc < 2 */
        {
            (*tsc)++;
            cout << *tsc << endl;
            return stairs[cur] + aw[cur - 1];
        }
    }
    else {
        (*tsc)++;
        cout << *tsc << endl;
        return stairs[0];
    }
}
int excludeStairs(int cur, int* aw)
{
    if(cur > 0) { return aw[cur - 1]; }
    else return 0;
}
