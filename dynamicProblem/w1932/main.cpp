#include <iostream>
#include <vector>

using namespace std;

/* To solve this *//*
  - We have to calculate the accumweight[level][index] that are amount calculated until 'index' in 'level'.
  - level=0 : 7(-)
  - level=1 : 3(10) 8(15)
  - level=2 : 8(18) 1(16) 0(15)
  - for example, If level is 1, the accumweight[1][0](= 3) can be calculated by accumweight[0][0] + current_weight(= 3)
  - Besides, If level is 2 and the index is 1, the accumweight[2][1](= 1) can be calculated by max(accumweight[1][0]
    , accumweight[1][1]) + current_weight(=1).

*/
/* def */
typedef struct stair
{
    stair() {weight=0;}
    int weight;
    friend istream& operator >>(istream& is, stair& s)
    {
         is >> s.weight;
         return is;
    };
} stair;

/* var */
vector < vector < stair > > stairinfo; //stairinfo[i][i]
vector < vector < int > > accumweight; //accum[i][i]

/* func */
void input_read();
void findStairCost();
void output_print();

int main()
{
    input_read();
    findStairCost();
    output_print();
    return 0;
}
void input_read()
{
    unsigned row=0, n;
    cin >> n;
    stairinfo.resize(n);
    while(row < n)
    {
        for(unsigned col=0; col <= row; ++col)
        {
            stair s;
            cin >> s;
            stairinfo[row].push_back(s);
        }
        ++row;
    }
}
void findStairCost()
{
    //Initializing
    vector < vector < stair > >::iterator it=stairinfo.begin() + 1;
    vector < vector < stair > >::iterator it_end=stairinfo.end();
    int level=1;
    vector < int > e;
    e.push_back(stairinfo[0][0].weight);
    accumweight.push_back(e);
    e.clear();

    //Set accumweight[i][i]
    for(; it != it_end; ++it)
    {
        for(unsigned item=0; item < it->size(); ++item)
        {
            int cur_weight=stairinfo[level][item].weight;
            if(0 < item && item < it->size()-1)
            {
                int lparent=accumweight[level-1][item-1], rparent=accumweight[level-1][item];
                e.push_back(max(lparent, rparent) + cur_weight);
            } else if(item == 0)
            {
                int parent=accumweight[level-1][item];
                e.push_back(parent + cur_weight);
            } else
            {
                int parent=accumweight[level-1][item-1];
                e.push_back(parent + cur_weight);
            }
        }
        accumweight.push_back(e);
        e.clear();
        level++;
    }
}
void output_print()
{
    //Find the largest cost  in the last level
    int last=accumweight.size()-1;
    vector < int >::iterator element=accumweight[last].begin();
    vector < int >::iterator element_end=accumweight[last].end();
    int res=-1;
    for(; element != element_end; ++element)
    {
        if(res < (*element)) { res = (*element);}
    }
    cout << res;
}
