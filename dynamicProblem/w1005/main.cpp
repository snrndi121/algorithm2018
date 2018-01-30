#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

/* var */
int goal;
vector < int > indegree;
vector < list < int > > rules;
vector < int > delay;
vector < int > res;

/* func */
void input_read();
void building_craft();
void print_res();

int main()
{
    int testcase;
    cin >> testcase;
    while(testcase-- > 0)
    {
        input_read();
        building_craft();
    }
    print_res();
    return 0;
}
void input_read()
{
    /* Initializing */
    /* Get numf of bulidings and their rules */
    int i = 0 , numOfBuliing = 0, numOfrules = 0, x = 0, y = 0;
    cin >> numOfBuliing >> numOfrules;
    indegree.resize(numOfBuliing);
    rules.resize(numOfrules);

    /* Get info about cost of buildings */
    int _d = 0;
    while(i++ < numOfBuliing) { cin >> _d; delay.push_back(_d);}

    /* Get info about process of craftings */
    i = 0;
    while(i < numOfrules)
    {
        cin >> x >> y;
        rules[x - 1].push_back(y - 1);
        indegree[y - 1]++;
        i++;
    }
    /* Get goal */
    cin >> goal;
}
void building_craft()
{
    /* Initializing */
    queue < int > searchQue;
    vector < int  > weight;
    unsigned sz = indegree.size();
    weight.resize(goal + 1);

    /* Set searchQue */
    for (unsigned i=0; i < sz; ++i)
    {
        if (indegree[i] == 0) { searchQue.push(i);}
    }
    int top = searchQue.front();
    weight[top] = delay[top];

    /* Set resQue */
    while (!searchQue.empty() && top != goal)
    {
        top = searchQue.front();
        searchQue.pop();

        /*step2. Set siblings from li[i] */
        for (list < int >::iterator it = rules[top].begin(); it != rules[top].end(); ++it)
        {
            int child = (*it);
            indegree[child]--;
            weight[child] = max(weight[child], weight[top] + delay[child]);
            if (indegree[child] == 0) { searchQue.push(child);}
        }
    }
    res.push_back(weight[goal - 1]);
}
void print_res()
{
    vector < int >::iterator it = res.begin();
    vector < int >::iterator it_end = res.end();
    for (; it != it_end; ++it) { cout << (*it) << endl;}
}
