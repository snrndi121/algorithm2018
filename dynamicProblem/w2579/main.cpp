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
  if( sizeOfstairs > 0)
  {
        int* accum_weight = new int[sizeOfstairs];
        bool* visit = new bool[sizeOfstairs];
        accum_weight[0] = stairs[sizeOfstairs - 1];
        int twostepCount = 1;
        for ( int i = 0; i < sizeOfstairs - 1; ++i) { visit[i] = false;}
        visit[sizeOfstairs - 1] = true;

        for (int i = 1; i < sizeOfstairs; ++i)
        {
              int target = sizeOfstairs - (i + 1);
              //cout << "\n > current back_stairs :" << stairs[target] << endl;
              //cout << " > tsc :" << twostepCount;
              if (twostepCount == 0)
              {
                  accum_weight[i] = accum_weight[i - 1] + stairs[target];
                  twostepCount++;
                  visit[target] = true;
                  //cout << "->" << twostepCount << endl;
              }
              else if (twostepCount == 1)
              {
                  accum_weight[i] = accum_weight[i - 1] + stairs[target];
                  twostepCount++;
                  visit[target] = true;
                  //cout << "->" << twostepCount << endl;
              }
              else  /* selection event */
              {
                  if ((target + 2 != sizeOfstairs -1)
                  && stairs[target + 2] < stairs[target + 1]
                  && stairs[target + 2] < stairs[target])
                  {   /* target > target +1 > target + 2*/
                      visit[i] = true;
                      //cout << "->" << twostepCount << endl;
                      //cout << " > ,swithching :" << stairs[target] << endl;
                      //cout << " > " << stairs[target + 2] << ", Is visit? " << visit[target + 2] << endl;
                      if ( visit[target + 3] != false)
                      {
                          accum_weight[i] = accum_weight[i - 3] + stairs[target] + stairs[target + 1];
                          visit[target + 3] = false;
                      }
                      else
                      {
                          accum_weight[i] =  accum_weight[i -3] + stairs[target] + stairs[target + 2];
                          visit[target + 1] = false;
                      }
                  }
                  else if(stairs[target] > stairs[target + 1])
                  {   /* target > target +1 */
                      twostepCount--;
                      visit[target] = true;
                      accum_weight[i] = accum_weight[i-2] + stairs[target];
                      //cout << "->" << twostepCount << endl;
                      //cout << " > ,then selec :" << stairs[target] << endl;
                  }
                  else
                  {   /* target < target +1 */
                      twostepCount = 0;
                      accum_weight[i] = accum_weight[i-1];
                      //cout << "->" << twostepCount << endl;
                      //cout << " > ,then select :" << stairs[target - 1] << endl;
                  }
              }
              //cout << " > accum :" << accum_weight[i] << endl;
        }
        cout << accum_weight[sizeOfstairs - 1] << endl;
    }
    else cout << 0;
}
